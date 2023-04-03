#include<stdio.h>

//declaration constante
#define AGE 18

void main(void)
{
	//declaration variable
	int moisNaissance, anneNaissance, annesActuel, difAnne;
	//saisi de valeur 
	printf("Donnez-votre date de naissance :\n");
	printf("Anne : ");
	scanf_s("%i", &anneNaissance);
	printf("Donnez la date actuel :\n");
	printf("Anne : ");
	scanf_s("%i", &annesActuel);
	//calcul de l'age 
	difAnne = annesActuel - anneNaissance;
	printf("%i\n", difAnne);
	if (difAnne >= AGE)
	{
		
		printf("Vous etes majeur");
	}
	else
	{
		printf("Vous-etes pas majeur.");
	}
}