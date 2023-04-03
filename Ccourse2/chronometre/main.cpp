#include <iostream>
#include <time.h> 
#include <Windows.h>
#include "CChrono.h"

using namespace std;

int main(void) 
{
	int var, minute, second, centieme;
	int taille;
	bool retour;
	char temps[12];
	unsigned short heure;
	CChrono monChrono;
	cout << "_____________________________________________________________________\n|                                  chono                            |\n_____________________________________________________________________" << endl;
	do
	{
		//cout "____________" << endl;
		cout << "1.Demarrer\n2.Arreter\n3.Reset\n4.Afficher nombre\n5.Afficher chaine de caractere\n0.Quitter" << endl;
		cin >> var;
		switch (var)
		{
		case 1:
			if (monChrono.Start()==true)
			{
				cout << "Le chronometre est demarre" << endl;
			}
			else
			{
				cout << "impossible le chronometre est deja demarre" << endl;
			}
			break;
		case 2 :
			if (monChrono.Stop() == true)
			{
				cout << "Le chronometre est arreter" << endl;
			}
			else
			{
				cout << "impossible le chronometre est deja arreter" << endl;
			}
			break;
		case 3:
			if (monChrono.Reset() == true)
			{
				cout << "Chronometre remit a Zero" << endl;
			}
			else
			{
				cout << "Arreter le chronometre avant de le remettre a zeros" << endl;
			}
			break;
		case 4:
			monChrono.lireTemps(&heure, &minute, &second, &centieme);
			cout << heure << ":" << minute << ":" << second << "." << centieme << endl;
			break;
		case 5:
			taille = 12;
			if (monChrono.lireTemps(temps, taille) == true)
			{
				cout << temps << endl;
			}
			else
			{
				cout << "La taille de la chaine de carractere est trop petit" << endl;
			}
			break;
		default:
			break;
		}
	} while (var != 0);
	cout << "Au revoir" << endl;
	temps[0] = '\0';
	return 0;
}



