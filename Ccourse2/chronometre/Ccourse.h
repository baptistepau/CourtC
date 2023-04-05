#pragma once
#include "CChrono.h"
#include "CParticipant.h"
class Ccourse
{
private:
	bool etatCourse		;
	CChrono leChrono;
	CParticipant lesParticipant[10];
public :
	Ccourse();
	~Ccourse();
	bool Demarrer();
	bool Arreter();
	bool reset();
	bool lireTempsCourse(char* temps, int taille);
	bool lireMeilleurTemps(int participant, char* temps, int taille);
	bool lireDerniersTempsTours(int participant, char* temps, int taille);
	int lireNbTours(int participant);
};

