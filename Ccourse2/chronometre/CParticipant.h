#pragma once
class CParticipant
{
private :
	int nbreTours;
	int meilleurTours;
	int dernierTemps;
	int horairePrecedentPasage;
public :
	CParticipant();
	~CParticipant();
	void demmarer();
	void ajouterTours(int time);
	bool lireMeilleurTours(char* temp, int taille);
	bool lireDernierTours(char* temp, int taille);
	int lireNbTours();
	void reset();
};

