#include <iostream>
using namespace std;
#define TMAX 50

void main(void)
{
	char chaine[TMAX];
	int cpt , cptCar;
	char car;

	cout << "Entrer la chaine de carractere" << endl;
	cin >> chaine;
	cout <<"Quelle carractere voulez-vous compter" << endl;
	cin >> car;
	cpt = 0;
	cptCar = 0;
	while (chaine[cpt] != '\0')
	{
		if (chaine[cpt] == car - 0x20 || chaine[cpt] == car)
		{
			cptCar++;
		}
		cpt++;
	}
	cout << "La chaine fait " << cpt << " carractere avec "<< cptCar<< "lettre " << car << endl;

}