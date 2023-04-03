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
	unsigned char tabDonn�es[6];

	tabDonn�es[0]=couleur;
	tabDonn�es[1]=gobo;
	tabDonn�es[2]=strobe;
	tabDonn�es[3]=PosX;
	tabDonn�es[4]=PosY;
	tabDonn�es[5]=Lum;
	pReseauDMX->MiseAjourDonneesDMX(tabDonn�es,premCanal,6);
}