#include"Par.h"
#include"odmxusb.h"
#include <process.h>
#include <stdio.h>

void main(void)
{
	// init r�seau dmx
	Open_USB_DMX LiaisonDMX;
	LiaisonDMX.open_dmx_devices();
	
	// cr�ation du projecteur avec l'adresse DMX 10
	CPar leProjecteur(10, &LiaisonDMX);
	
	// Pour changer la puissance
	leProjecteur.ChangePuiss(255);

	// d�claration des variables
	byte tauxDeRouge = 0, tauxDeVert = 0, tauxDeBleu = 0;

	while (true)
	{
		// c'est ici que vous devez mettre votre code
		







	}
}

