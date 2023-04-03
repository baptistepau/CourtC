#include<stdio.h>

//declaration constante
#define AGE 18

void main(void)
{
	//declaration variable
	int jourNaissance, moisNaissance, anneNaissance, jourActuel, moisActuel, annesActuel, difAnne, difMois;
	//saisi de valeur 
	printf("Donnez-votre date de naissance :\n");
	printf("Jour naissance : ");
	scanf_s("%i", &jourNaissance);
	printf("Mois naissance : ");
	scanf_s("%i", &moisNaissance);
	printf("Anne naissance : ");
	scanf_s("%i", &anneNaissance);
	printf("Donnez la date actuel :\n");
	printf("Jour actuel: ");
	scanf_s("%i", &jourActuel);
	printf("Mois actuel: ");
	scanf_s("%i", &moisActuel);
	printf("Anne actuel: ");
	scanf_s("%i", &annesActuel);
	//calcul de l'age 
	difAnne = annesActuel - anneNaissance;
	difMois = moisNaissance - moisActuel;
	//Verification
	if (difAnne >= 19 || difAnne >= AGE && moisActuel >= moisNaissance || difAnne >= AGE && difMois ==  0 && jourActuel <= jourNaissance)
	{
		printf("Vous etes majeur");
	}
	else
	{
		printf("Vous-etes pas majeur.");
	}
}