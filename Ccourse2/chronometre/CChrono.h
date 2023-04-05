#pragma once
#include <Windows.h>
class CChrono
{
private :
	bool etat;
	unsigned long clockStart;
	unsigned long clockStop;
public :
	CChrono();
	~CChrono();
	bool Start();
	bool Stop();
	bool Reset();
	void lireTemps(unsigned short* h, int* mn, int* s, int* c);
	bool lireTemps(char* temp, int taille);
	int lireHoraire();
	bool getEtatChrono();
};

