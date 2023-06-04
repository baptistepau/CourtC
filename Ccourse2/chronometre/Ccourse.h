#pragma once
#include "CChrono.h"
#include "CParticipant.h"

#define MAXPARTICIPANT 10

class Ccourse
{
private:
	CChrono leChrono;
	CParticipant lesParticipant[MAXPARTICIPANT];
public :
	Ccourse();
	~Ccourse();
	bool Demarrer();
	bool Arreter();
	bool lireTempsCourse(char* temps, int taille);
	bool lireMeilleurTemps(int participant, char* temps, int taille);
	bool lireDerniersTempsTours(int participant, char* temps, int taille);
	int lireNbTours(int participant);
	bool AjoutTours(int participant);
};

