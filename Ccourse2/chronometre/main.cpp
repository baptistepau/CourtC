#include <iostream>
#include <time.h> 
#include <Windows.h>
#include "Ccourse.h"

using namespace std;

int main(void) 
{
	char temps[12];
	int varleurBoucle ,taille , varParticipant;
	Ccourse laCourse;
	cout << "_____________________________________________________________________\n|                                  course                            |\n_____________________________________________________________________" << endl;
	do
	{
		cout << "1.Demarrer la course\n2.Arreter la course\n3.Remettre a zero\n4.Temps de course\n5.Meilleur temps\n6.Derniers temps\n7.Nombre de tours\n8.Ajouter un tours\n0.Quitter" << endl;
		cin >> varleurBoucle;
		switch (varleurBoucle)
		{
		case 1:
			if (laCourse.Demarrer() == true)
			{
				cout << "La course est demarrer" << endl;
			}
			else
			{
				cout << "La course et deja demarrer" << endl;
			}
			break;
		case 2 :
			if (laCourse.Arreter() == true)
			{
				cout << "La course est arreter" << endl;
			}
			else
			{
				cout << "demarer la course avant de l'arreter" << endl;
			}
			break;
		case 3 :
			if (laCourse.reset() == true)
			{
				cout << "La course a ete remis a zero" << endl;
			}
			else
			{
				cout << "Avant de remettre la course a zero arreter la" << endl;
			}
			break;
		case 4 :
			taille = 12;
			if (laCourse.lireTempsCourse(temps, taille) == true)
			{
				cout << "La course est en court depuis " << temps << endl;
			}
			else
			{
				cout << "La taille du tableau est trop petit" << endl;
			}
			break;
		case 5 :
			taille = 12;
			do
			{
				cout << "Quelle prarticipant voulez-vous voir le meilleur temps  : [0 a 10 ]" << endl;
				cin >> varParticipant;
			} while (varParticipant >= 10);
			if (laCourse.lireMeilleurTemps(varParticipant, temps, taille) == true)
			{
				cout << "La meilleur course du participant " << varParticipant << " est " << temps << endl;
			}
			else
			{
				cout << "La taille de la chaine de carractére est trop petite" << endl;
			}
			break;
		case 6 :
			taille = 12;
			do
			{
				cout << "Quelle prarticipant voulez-vous voir le temps du dernier tours : [0 a 10 ]" << endl;
				cin >> varParticipant;
			} while (varParticipant >= 10);
			if (laCourse.lireMeilleurTemps(varParticipant, temps, taille) == true)
			{
				cout << "Le dernier temps du participant " << taille << " est " << temps << endl;
			}
			else
			{
				cout << "La taille de la chaine de carractére est trop petite" << endl;
			}
			break;
		case 7 :
			do
			{
				cout << "Quelle prarticipant voulez-vous voir le nombre de tours : [0 a 10 ]" << endl;
				cin >> varParticipant;
			} while (varParticipant >= 10);
			cout << "Le nombre de de tours du participant " << varParticipant << " est " << laCourse.lireNbTours(varParticipant) << endl;
			break;
		case 8 :
			do
			{
				cout << "Quelle prarticipant voulez-vous rajouter un tours : [0 a 10 ]" << endl;
				cin >> varParticipant;
			} while (varParticipant >= 10);
			if (laCourse.AjoutTours(varParticipant) == true)
			{
				cout << "Tour ajouter" << endl;
			}
			else
			{
				cout << "Verifier que la course est demarer" << endl;
			}
			break;
		default:
			break;
		}
	} while (varleurBoucle != 0);
	cout << "Au revoir" << endl;
	return 0;
}



