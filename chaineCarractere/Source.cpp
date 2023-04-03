#include <iostream>
#include "CChaine.h"

using namespace std;

int main()
{
	int rep;
	CChaine MaChaine;
	char leMots[50];
	int nbCar;
	char lettre;
	int nbLettre;
	cout << "Ecriver votre mot : " << endl;
	cin >> leMots;
	cout << "Combien de caractere compte votre chaine" << endl;
	cin >> nbCar;
	MaChaine.setChaine(leMots, nbCar);
	do
	{
		cout << "\nQue voulez-vous faire?\n\n 1. Majuscule \n 2. Minuscule \n 3. Supprimer tout une lettre \n 4. Supprimer un caractere \n 5. Compter le nombre de caratere \n 6. Compter le nombre d'ocurence d'un caratere \n 7. Inverser la chaine \n 8. inserer un caractere \n 9. Quitter" << endl;
		cin >> rep;
		cout << "Chaine avant modification :" << leMots << endl;
		switch (rep)
		{
		case 1:
			MaChaine.majuscule();
			MaChaine.getChaine(leMots, 50);
			cout << "Passage en majuscule : " << leMots << endl;
			break;
		case 2:
			MaChaine.minuscule();
			MaChaine.getChaine(leMots, 50);
			cout << "Passage en miniscule: " << leMots << endl;
			break;
		case 3:
			cout << "Quelle caractere voulez-vous supprimer" << endl;
			cin >> lettre;
			MaChaine.supprimerCar(lettre);
			MaChaine.getChaine(leMots, 50);
			cout << "Suppression du caractere " << lettre << ": " << leMots << endl;
			break;
		case 4:
			cout << "Quelle numero de caractére voulez-vous supprimer ?" << endl;
			cin >> nbLettre;
			MaChaine.supprimerCar(nbLettre);
			MaChaine.getChaine(leMots, 50);
			cout << "Suppression du caractere " << nbLettre << ": " << leMots << endl;
			break;
		case 5 :
			cout << "Nombre carractére de la chaine: " << MaChaine.getNbCar() << endl;
			break;
		case 6 :
			cout << "Quelle caractere voulez-vous compter ?" << endl;
			cin >> lettre;
			cout <<"Il a " << MaChaine.ocurence(lettre)<< " caractere " << lettre <<" dans la chaine " << endl;
			break;
		case 7 : 
			MaChaine.reverse();
			MaChaine.getChaine(leMots,50);
			cout << leMots << endl;
		case 8 :
			cout << "Quelle lettre voulez inserer ?" << endl;
			cin >> lettre;
			cout << "A quelle position voulez-vous inserer ?" << endl;
			cin >> nbLettre;
			MaChaine.insererCar(lettre, nbLettre);
			MaChaine.getChaine(leMots,50);
			cout << leMots <<endl;
		default:
			break;
		}
	} while (rep !=9);
	cout << "Au revoir" << endl;
	return 0;
}
