#include <stdio.h>
#include <windows.h>
#include "Scan.h"

void main(void)
{
	// Variables
	Open_USB_DMX ReseauDMX;
	int retour = ReseauDMX.open_dmx_devices();
	CScan LeProj1(1,&ReseauDMX);
	CScan LeProj2(10, &ReseauDMX);
	int couleur, gobo, posX, posY, lum, strobe=255;

	// *************** Programme élève *************** //
	do
	{

		//LeProj1.EnvoyerCommande(couleur,gobo,posX,posY,lum,strobe);



	} while (/*pas terminé*/true);
	ReseauDMX.close_dmx_devices();
}