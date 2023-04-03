#include "Scan.h"


CScan::CScan(int adresse)
{
	premCanal=adresse;
	int retour=ReseauDMX.open_dmx_devices();
}


CScan::~CScan(void)
{
		ReseauDMX.close_dmx_devices();

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
	ReseauDMX.MiseAjourDonneesDMX(tabDonnées,premCanal,6);
}