#include <iostream>
#include <time.h> 
#include <Windows.h>
#include "CChrono.h"

using namespace std;

int main(void) 
{
	int var;
	CChrono coureur;
	cout << "_____________________________________________________________________\n|                                  chono                            |\n_____________________________________________________________________" << endl;
	cout << "1.Ccoureur\n2.Ccourse\n0.Quitter" << endl;
	cin >> var;
	switch (var)
	{
	case 1:
		var = 100;
		do
		{
			
			cout << "1.Demarer\n2.Arreter\n3.Reset\n4.Tours\n5.Meileur tours\n6.Nombre de tours\n0.Quitter" << endl;
			cin >> var;
			switch (var)
			{
			case 1:
				if (coureur.Start() == true)
				{
					cout << "Le coureur est demarer" << endl;
				}
				else
				{
					cout << "Le coureurest deja demarer" << endl;
				}
				break;
			case 2:
				if (coureur.Stop() == true)
				{
					cout << "Le coureur est arreter" << endl;
				}
				else
				{
					cout << "Le coureur n'a pas demarer" << endl;
				}
				break;
			case 3:
				if (coureur.Reset() == true)
				{
					cout << "les valeur du coureur a été remis a zero" << endl;
				}
				else
				{
					cout << "Arreter le coureur avant de le remettre a zero" << endl;
				}
				break;
			case 4:
				if (coureur.tours() == true)
				{
					cout << "Tours compter" << endl;
				}
				else
				{
					cout << "Dememarer le coureur avant de compter les tours" << endl;
				}
				break;
			case 5:
				cout << "Le meilleur temps du coureur est " << coureur.getMeilleurTemps() << " " << endl;
				break;
			case 6:
				cout << "Le coureur a fais " << coureur.getnbTours() <<" " << endl;
				break;
			default:
				break;
			}
		} while (var != 0);
		break;
	case 2 :
		break;
	default:
		break;
	}
	cout << "Au revoir" << endl;
	return 0;
}



