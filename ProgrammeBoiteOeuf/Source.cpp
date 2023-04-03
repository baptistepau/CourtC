#include <stdio.h>

#define NOMBREEMPLACEMENT 6 

void main(void)
{
	unsigned int nbOeuf, nbBoite, nbReste;
	printf("Entrer le nombre d'oeuf produit pendant une journee : ");
	scanf_s("%i", &nbOeuf);
	nbBoite = nbOeuf / NOMBREEMPLACEMENT;
	nbReste = nbOeuf % NOMBREEMPLACEMENT;
	printf("On peut faire %i boite et il reste %i Oeuf", nbBoite, nbReste);
}