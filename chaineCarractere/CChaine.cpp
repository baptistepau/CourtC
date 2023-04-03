#include "CChaine.h"

CChaine::CChaine()
{
	tableau[0] = '\0';
	longueur = 0;
}


CChaine::CChaine(char mot[], int taille)
{
	tableau[taille] = mot[taille];
}

CChaine::~CChaine()
{
	// 
}

bool CChaine::getChaine(char mot[], int taille)
{
	int i;
	for (i = 0; i < taille; i++)
	{
		mot[i] = tableau[i];
	}
	return false;
}

bool CChaine::setChaine(char mot[], int taille)
{
	int i;
	if (taille > (MAXTAB-1))
	{
		return false;
	}
	
	for (i = 0; i < taille; i++)
	{
		tableau[i] = mot[i];
	}
	tableau[taille] = '\0';
	longueur = taille;
	return true;
}

void CChaine::majuscule()
{
	int i;
	for (i = 0; i < longueur; i++)
	{
		if (tableau[i] > 'a' && tableau[i] <= 'z')
			tableau[i] -= 0x20; // ou 32,0x c'est de l'Hexa
	}

}

void CChaine::minuscule()
{
	int i;
	for (i = 0; i < longueur; i++)
	{
		if (tableau[i] > 'A' && tableau[i] <= 'Z')
		{
			tableau[i] = tableau[i] + 0x20;
		}
	}

}

int CChaine::getNbCar()
{
	int cpt = 0;
	while (tableau[cpt] != '\0')
	{
		cpt++;
	}
	return cpt;
}
int CChaine::ocurence(char lettre)
{
	int i = 0 , cpt = 0;

	while (longueur >= i)
	{
		if ((tableau[i] == lettre) || (tableau[i] == lettre - 0x20))
		{
			cpt++;
		}
		i++;
	}
	return cpt;
}
bool CChaine::supprimerCar(char lettre)
{
	int i = 0 , j;

	while (tableau[i] !='\0')
	{
		if (tableau[i] == lettre)
		{// decaler tout le reste
			longueur--;
			j = i;
			while (tableau[j] != '\0')
			{
				tableau[j] = tableau[j + 1];
				j++;

			}
		}
		else
		{
			i++;
		}
	}
	return true;
}
bool CChaine::supprimerCar(int possistion) 
{
	int i = 0,j;
	while (i <= longueur)
	{
		j = i;
		if (i == possistion-1)
		{
			while (tableau[j] != '\0')
			{
				tableau[j] = tableau[j + 1];
				j++;
			}
		}
		i++;
	}
	longueur--;
	return false;
}
void CChaine::reverse()
{
	int i,j;
	char tampons;
	j = longueur - 1;
	for (i = 0; i < (longueur/2); i++)
	{
		tampons = tableau[i];
		tableau[i] = tableau[j];
		tableau[j] = tampons;
		j--;
	}
}

bool CChaine::insererCar(char lettre, int position)
{
	int i;
	if (position > longueur)
	{
		return false;
	}
	else
	{
		for (i = longueur; i > position - 1; i--)
		{
			tableau[i] = tableau[i - 1];
		}
		tableau[position - 1] = lettre;
		longueur++;
		tableau[longueur] = '\0';
		return true;
	}
}