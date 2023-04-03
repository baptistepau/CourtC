#include "Scan.h"


CScan::CScan(int Adresse, Open_USB_DMX* pLiaison)
{
	premCanal=Adresse;
	pReseauDMX = pLiaison;
	
}


CScan::~CScan(void)
{

}
void CScan::EnvoyerCommande(int couleur, int gobo, int PosX,int PosY,int Lum, int strobe)
{
	unsigned char tabDonnées[6];

	tabDonnées[0]=couleur;
	tabDonnées[1]=gobo;
	tabDonnées[2]=strobe;
	tabDonnées[3]=PosX;
	tabDonnées[4]=PosY;
	tabDonnées[5]=Lum;
	pReseauDMX->MiseAjourDonneesDMX(tabDonnées,premCanal,6);
}