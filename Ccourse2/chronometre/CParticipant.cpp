#include <time.h>
#include <stdio.h>
#include "CParticipant.h"

CParticipant::CParticipant()
{
	nbreTours = 0;
	meilleurTours = 0;
	dernierTemps = 0;
	horairePrecedentPasage = 0;
}
CParticipant::~CParticipant()
{

}
void CParticipant::demmarer()
{
	horairePrecedentPasage = clock();
}
void CParticipant::ajouterTours(int time)
{
	nbreTours++;
	dernierTemps = time - horairePrecedentPasage;
	horairePrecedentPasage = time;
	if ((dernierTemps <= meilleurTours) || (meilleurTours == 0))
	{
		meilleurTours = dernierTemps;
	}

}
bool CParticipant::lireMeilleurTours(char* temp, int taille)
{
	float fcentieme;
	int secondes, minutes, heures, centiemes;
	fcentieme = (float)meilleurTours / CLOCKS_PER_SEC;
	secondes = (int)fcentieme;
	centiemes = (int)(fcentieme - secondes) * 100;
	heures = secondes / 3600;
	minutes = (secondes % 3600) / 60;
	secondes = secondes % 60;
	if (sprintf_s(temp, taille, "%d:%d:%d.%d", heures, minutes, secondes, centiemes) == -1)
	{
		return false;
	}
	else
	{
		return true;

	}

}
bool CParticipant::lireDernierTours(char* temp, int taille)
{
	float fcentieme;
	int secondes, minutes, heures, centiemes;
	fcentieme = (float)dernierTemps / CLOCKS_PER_SEC;
	secondes = (int)fcentieme;
	centiemes = (int)(fcentieme - secondes) * 100;
	heures = secondes / 3600;
	minutes = (secondes % 3600) / 60;
	secondes = secondes % 60;
	if (sprintf_s(temp, taille, "%d:%d:%d.%d", heures, minutes, secondes, centiemes) == -1)

	{
		return false;
	}
	else
	{
		return true;

	}
}
int CParticipant::lireNbTours()
{
	return nbreTours;
}
void CParticipant::reset()
{
	nbreTours = 0;
	meilleurTours = 0;
	dernierTemps = 0;
	horairePrecedentPasage = 0;
}