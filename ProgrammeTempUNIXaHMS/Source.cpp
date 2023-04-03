#include <stdio.h>

void main(void)
{
	unsigned long nbSecondTotal, nbHeure;
	unsigned short nbMinute, nbSecond;
	//saisi des valeur
	printf("Entrer le nombre de second UNIX : ");
	scanf_s("%u", &nbSecondTotal);
	//calcul
	nbHeure = nbSecondTotal / 3600;
	nbSecondTotal = nbSecondTotal % 3600;
	nbMinute = nbSecondTotal / 60;
	nbSecondTotal = nbSecondTotal % 60;
	printf("Il est %i H %i m %i s",nbHeure,nbMinute,nbSecondTotal);
}