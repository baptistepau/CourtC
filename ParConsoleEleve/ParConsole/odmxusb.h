#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#ifndef t_dmx_senderH
#define t_dmx_senderH

#include <windows.h>
//#include <boost/thread/thread.hpp>

#include "FTD2XX.h"

class Open_USB_DMX
{
private:

	bool connected;
	HANDLE hThread;
	unsigned long ThreadId;
	unsigned char DMXData_frame1[512];
	FT_HANDLE ftHandle; 
	int ftDeviceCount;
public:

	bool DonneesDispo;
	Open_USB_DMX();
	~Open_USB_DMX();

	int open_dmx_devices();
	int close_dmx_devices();
	bool MiseAjourDonneesDMX(unsigned char* data,int AdDebut,int NbDonnees);
	int SendDataToHardware();

};

#endif