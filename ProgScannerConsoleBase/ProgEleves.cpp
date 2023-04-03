#include <stdio.h>
#include <windows.h>
#include "Scan.h"

#define NBCOLOR 15 

void main(void)
{
	// Variables

	CScan LeProj(1);
	int rep;
	int couleur,gobo,posX,posY,lum,strobe,x,valeur;

	// *************** Programme élève *************** //
	couleur = 255 / 17;
	gobo = 255 / 17;
	posX = 50;
	posY = 0;
	lum = 100;
	do
	{
		printf("1.Couleur\n2.Gobo\n3.Possition en X\n4.Possition en Y\n5.Luminositer\n0.Quitter\n");
		scanf_s("%i", &rep);
		switch (rep)
		{
		case 1:
			printf("\nCouleur : ");
			scanf_s("%i", &valeur);
			couleur = (valeur / 255)*(NBCOLOR-255/NBCOLOR/5);
			break;
		case 2:
			printf("Gobo : ");
			scanf_s("%i", &valeur);
			gobo = (valeur / 255) * (NBCOLOR - 255 / NBCOLOR / 5);
			break;
		case 3:
			printf("possition en X : ");
			scanf_s("%i", &posX);
			break;
		case 4:
			printf("possition en Y : ");
			scanf_s("%i", &posY);
			break;
		case 5:
			printf("Luminositer : ");
			scanf_s("%i", &lum);
			lum = lum * 100 / 255;
			break;
		default :
			break;
		}
		LeProj.EnvoyerCommande(couleur, gobo, posX, posY, lum);
		printf("envoye au proj\n");
		printf("Couleur = %i \nGobo = %i \nPosx = %i \nposY = %i \nLum = %i\n", couleur, gobo, posX, posY, lum);
	} while (rep != 0);
	
	// *************** Fin programme élève *************** //

}