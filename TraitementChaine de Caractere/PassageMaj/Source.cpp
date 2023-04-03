#include <iostream>
using namespace std;
#define TMAX 50

void main(void)
{
	char chaine[TMAX];
	int cpt;
	

	cout << "Entrer la chaine de carractere" << endl;
	cin >> chaine;
	cout << "Quelle carractere voulez-vous compter" << endl;
	cpt = 0;
	
	while (chaine[cpt] != '\0')
	{
		if (chaine[cpt] >= 0x61)
		{
			chaine[cpt] = chaine[cpt] - 0x20;
		}
		cpt++;
	}
	cout << chaine << endl;
	

}