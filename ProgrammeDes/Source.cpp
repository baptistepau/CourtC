#include <stdio.h>
#include <time.h> // pour connaitre l'heure 
#include <stdlib.h> // pour generer des nombre aleatoir

void main(void)
{
	int des1, des2;
	int nbLancer = 0;
	srand(time(NULL));
	do
	{
		printf("Lancer %i\n", nbLancer);
		des1 = (rand() % 6) + 1;
		des2 = (rand() % 6) + 1;
		printf("Resultat de des 1 = %i\nResultat de des 2 = %i\n\n", des1, des2);
		nbLancer = nbLancer + 1;
	} 
	while (des1 != des2);

	printf("On a obtenu un double au bout de %i\n", nbLancer);
	


	

}
