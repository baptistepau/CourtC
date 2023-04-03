#include <stdio.h>
#include "Test.h"


void main(void)
{
	printf("Interro POINTEUR\n");

	char chaine[10] = "Bonjour";
	printf("La chaine du debut : %s\n", chaine);

	CTest MonTest;

	MonTest.Rempl(chaine);
	printf("La chaine modifie : %s\n", chaine);

	int monEntier = 99;
	printf("Le nombre du debut : %i\n", monEntier);

	MonTest.Rent(&monEntier);
	printf("Le nombre modifie : %i\n", monEntier);
}
