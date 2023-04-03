#include <stdio.h>

void main(void)
{
	double coefA, coefB, solutionX;
	printf("Donnez  la valeur de A");
	scanf_s("%lf", &coefA);
	if (coefA != 0)
	{
		printf("Donnez la valeur de B");
		scanf_s("%lf", &coefB);
		solutionX = -coefB / coefA;
		printf("La solution : %f", solutionX);
	}
	else
	{
		printf("Ce n'est pas possible de diviser par 0");
	}
}