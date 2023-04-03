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
	unsigned char tabDonn�es[6];

	tabDonn�es[0]=couleur;
	tabDonn�es[1]=gobo;
	tabDonn�es[2]=strobe;
	tabDonn�es[3]=PosX;
	tabDonn�es[4]=PosY;
	tabDonn�es[5]=Lum;
	ReseauDMX.MiseAjourDonneesDMX(tabDonn�es,premCanal,6);
}