#include <stdio.h>

void main(void)
{
	//declaration variable
	int i,table ;
	// saisi valeur
	printf("Quelle table voulez-vous avoir ?");
	scanf_s("%i", &table);
	// boucle et calcule
	for (i = 1; i < 13; i++)
	{
		
		printf("%i * %i = %i\n", table, i, table * i);
	}
}