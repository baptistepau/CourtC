#pragma once
class CParticipant
{
private :
	int nbreTours;
	int meileurTours;
	int dernierTemps;
	int horairePrecedentPasage;
public :
	CParticipant();
	~CParticipant();
	void ajouterTours(int time);
	bool lireMeilleurTours(char* temp, int taille);
	bool lireDernierTours(char* temp, int taille);
	int lireNbTours();

};

