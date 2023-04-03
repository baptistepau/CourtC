#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(void)
{
	//initialisation du radom
	srand(time(NULL));
	char relancer, reponse;
	// declaration varriable
	int de1, de2, totalDeJ1, totalDeJ2;
	int compteurJ1;
	int compteurJ2;

	do
	{
		compteurJ1 = 0;
		compteurJ2 = 0;
		
		printf("Bienvenu dans le jeux du de\n");
		printf("Le joueur 1 commence\n");
		do
		{
			de1 = rand() % 6 + 1;
			de2 = rand() % 6 + 1;
			compteurJ1++;
			printf("\tVous avez optenu %i et vous avez fait %i lancer\n", de1 + de2, compteurJ1);
			do
			{
				printf("\tVoulez-vous relancez  les des ? [O/N] : ");
				scanf_s(" %c", &relancer);
			} 
			while ((relancer != 'O') && (relancer != 'N') && (relancer != 'o') && (relancer != 'n'));
			printf("______________________________________________\n");
		} 
		while (relancer == 'O' || relancer == 'o');
		totalDeJ1 = de1 + de2;
		printf("Le joueur numero 1 a fait % i lancer avec un score de %i\n", compteurJ1, totalDeJ1);
		
		printf("C'est le tour du joueur 2 de de jouer\n");
		do
		{
			de1 = rand() % 6 + 1;
			de2 = rand() % 6 + 1;
			compteurJ2++;
			printf("\tVous avez optenu %i et vous avez fait %i lancer\n", de1 + de2, compteurJ2);
			if (compteurJ2 != compteurJ1)
			{
				do
				{
					printf("\tVoulez-vous relancez  les des ? [O/N] : ");
					scanf_s(" %c",&relancer);
				} while ((relancer != 'O') && (relancer != 'N') && (relancer != 'o') && (relancer != 'n'));
			}
			else
			{
				relancer = 'N';
			}
			printf("______________________________________________\n");
		} 
		while ((compteurJ2 < compteurJ1) && (relancer == 'O'));
		
		totalDeJ2 = de1 + de2;
		if ((totalDeJ2 == totalDeJ1) && (compteurJ1 == compteurJ2))
		{
			printf("Egalite");
		}
		else
		{
			if (totalDeJ2 == totalDeJ1 && (compteurJ1 >= compteurJ2))
			{
				printf("Le joueur 2 a gagner");
			}
			else
			{
				if (totalDeJ2 == totalDeJ1 && (compteurJ1 <= compteurJ2))
				{
					printf("Le joueur 1 a gagner");
				}
				else 
				{
					if (totalDeJ1 > totalDeJ2)
					{
						printf("Le joueur 1 a gagner");
					}
					else 
					{
						if (totalDeJ1 < totalDeJ2)
						{
							printf("Le joueur 2 a gagner");
						}
					}
				}
			}
		}
		printf("______________________________________________\n");
		do
		{
			printf("\nVoulez-vous relancer une partie [O/N] : ");
			scanf_s(" %c", &reponse);

		} 
		while ((reponse != 'O') && (reponse != 'N') && (reponse != 'o') && (reponse != 'n'));
	} 
	while ((reponse == 'O') || (reponse == 'o'));
}