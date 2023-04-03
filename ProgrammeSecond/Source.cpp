#include <stdio.h>

void main(void)
{
	//declaration variable
	int minute, second, secondTotal;
	//saisi des valeur
	printf("Nombre de minute restante");
	scanf_s("%i", &minute);
	printf("Nombre de second restante");
	scanf_s("%i", &second);
	secondTotal = (minute * 60) + second;
	printf("Il reste %i second\n", secondTotal);
}