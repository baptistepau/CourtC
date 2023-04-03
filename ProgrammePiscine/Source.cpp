#include <stdio.h>

void main(void)
{
	//declaration varriable
	float coteDeLaPiscine, volume, profondeur;
	//saisir les valeurs
	printf("Donne moi la taille du cote ?");
	scanf_s("%f", &coteDeLaPiscine);
	printf("Donne moi la profondeur");
	scanf_s("%f", &profondeur);
	//calcul
	volume = coteDeLaPiscine * coteDeLaPiscine * profondeur * 1000;
	printf("Le volume est %3f litres\n", volume);
}