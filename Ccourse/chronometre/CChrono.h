#pragma once
#include <Windows.h>
class CChrono
{
private :
	bool etat;
	unsigned long clockStart;
	unsigned long clockStop;
	int nbTours;
	int meilleurTours;
public :
	CChrono();
	~CChrono();
	bool Start();
	bool Stop();
	bool Reset();
	void lireTemps(unsigned short* h, int* mn, int* s, int* c);
	bool lireTemps(char* temp, int taille);
	bool tours();
	int getMeilleurTemps();
	int getnbTours();
};

