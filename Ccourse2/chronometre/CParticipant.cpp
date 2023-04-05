#include <time.h>
#include <stdio.h>
#include "CParticipant.h"

bool CParticipant::transformationHorraire(char *temp,int taille,int temps)
{
	float fcentieme;
	int secondes, minutes, heures, centiemes;
	fcentieme = (float)temps / CLOCKS_PER_SEC;
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
	nbreTours = 0;
	meilleurTours = 0;
	dernierTemps = 0;
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
	return transformationHorraire(temp, taille,meilleurTours);
}
bool CParticipant::lireDernierTours(char* temp, int taille)
{
	return transformationHorraire(temp, taille, dernierTemps);
}
int CParticipant::lireNbTours()
{
	return nbreTours;
}