#include <time.h>
#include "CParticipant.h"

CParticipant::CParticipant()
{
	nbreTours = 0;
	meileurTours = 0;
	dernierTemps = 0;
	horairePrecedentPasage = 0;
}
CParticipant::~CParticipant()
{

}
void CParticipant::ajouterTours(int time)
{
	nbreTours++;
	dernierTemps = time - horairePrecedentPasage;
	horairePrecedentPasage = time;
	if ((dernierTemps >= meileurTours) || (meileurTours == 0))
	{
		meileurTours = dernierTemps;
	}

}
bool CParticipant::lireMeilleurTours(char* temp, int taille)
{
	float fcentieme;
	int secondes, minute, heure, centieme;
	fcentieme = meileurTours / CLOCKS_PER_SEC;

}
bool CParticipant::lireDernierTours(char* temp, int taille)
{
	return true;
}
int CParticipant::lireNbTours()
{

}
