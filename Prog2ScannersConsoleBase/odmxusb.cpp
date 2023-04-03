// *************************************************
// open_dmxusb.cpp  


#include "odmxusb.h"
#pragma comment(lib,"FTD2XX.lib")

// ***********************************************************************
// Thread de communication dmx
// ***********************************************************************

DWORD WINAPI ThreadCom(LPVOID pLiaison)
	
{  
	while(1)
	{
		//Attente données valides
		while(!(((Open_USB_DMX*)pLiaison)->DonneesDispo));
		//Expédition données
		((Open_USB_DMX*)pLiaison)->SendDataToHardware();
		Sleep(30);
	}
}

// ***********************************************************************
// Classe Open_Usb_Dmx
// ***********************************************************************


// Constructor
Open_USB_DMX::Open_USB_DMX() 
{ 
	//mise a 0 de toutes les données dmx
	for (int i=0;i<512;i++)
		DMXData_frame1[i]=0;
	
	ftDeviceCount = 0;
	connected = false;
}

// Destructeur
Open_USB_DMX::~Open_USB_DMX()
{
	// termine le thread d'envoi de données
	TerminateThread(hThread , 10);
}

// ouverture bus dmx
int Open_USB_DMX::open_dmx_devices()
{
    ftDeviceCount = 0;

	FT_STATUS ftStatus;

	if (!connected) 
	{

		ftStatus = FT_Open(0, &ftHandle);
		if(!FT_SUCCESS(ftStatus))			
			return 0;

	    ftDeviceCount = 1;

		// reset the devices
	    ftStatus = FT_ResetDevice(ftHandle);
	    if (!FT_SUCCESS(ftStatus)) 
			return -1; // Device not responding

		// Set the baud rate 12 will give us 250Kbits
		ftStatus = FT_SetDivisor(ftHandle,12);
	    if (!FT_SUCCESS(ftStatus)) 
			return -2; // Set baud rate error

		// Set the data characteristics
	    ftStatus = FT_SetDataCharacteristics(ftHandle,FT_BITS_8,FT_STOP_BITS_2,FT_PARITY_NONE);
	    if (!FT_SUCCESS(ftStatus)) 
			return -3; // Set Data Characteristics error

		// Set flow control
		ftStatus = FT_SetFlowControl(ftHandle, FT_FLOW_NONE, NULL, NULL );
	    if (!FT_SUCCESS(ftStatus)) 
		{
			return -4;
		}

		// set RS485 for sendin
		FT_ClrRts(ftHandle);

		// Clear TX RX buffers
		FT_Purge(ftHandle,FT_PURGE_TX | FT_PURGE_RX);

		Sleep(1000);

		// Start the thread
		hThread = CreateThread(NULL,NULL,ThreadCom,this, NULL, &ThreadId);

		connected = true;	

	}
	return ftDeviceCount;

}


// fermeture bus dmx
int Open_USB_DMX::close_dmx_devices()
{
	// termine le thread d'envoi de données
	TerminateThread(hThread , 10);
	if ((connected) && (ftDeviceCount>0))
		FT_Close(ftHandle);
	
	return 0;
}

// envoi des données locales sur le bus

int Open_USB_DMX::SendDataToHardware()
{
	// envoi de données sur le bus dmx
	
	ULONG bytesWritten;
	unsigned char	StartCode = 0;

	//prise de la ligne
	FT_SetBreakOn(ftHandle);
    FT_SetBreakOff(ftHandle);
	// Ecriture start code
	FT_Write(ftHandle, &StartCode, 1, &bytesWritten);
	//Ecriture données 
	FT_Write(ftHandle, DMXData_frame1, 512, &bytesWritten);
	
	return 0;
}

// mise a jour des données locales

bool Open_USB_DMX::MiseAjourDonneesDMX(unsigned char* data,int AdDebut,int NbDonnees)
{
	if((AdDebut<0)||(AdDebut+NbDonnees>511)||(NbDonnees<1))
		return false;
	DonneesDispo=false;	
	memcpy(DMXData_frame1+AdDebut-1, data, NbDonnees);
	DonneesDispo=true;
	return true;
}
