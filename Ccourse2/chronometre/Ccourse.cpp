#include "Ccourse.h"
#include <stdio.h>
#include <time.h>

Ccourse::Ccourse()
{

}

Ccourse::~Ccourse()
{

}
bool Ccourse::Demarrer()
{
	if (leChrono.Start() == true)
	{
		for (int i = 0; i < 10; i++)
		{
			lesParticipant[i].demmarer();
		}
		return true;
	}
	else
		return false;
}

bool Ccourse::Arreter()
{
	if (leChrono.Stop() == true)
		return true;
	else
		return false;
}


bool Ccourse::lireTempsCourse(char* temps, int taille)
{
	int secondes,centieme,heure,minutes;
	float horaire;
	horaire = (float)(leChrono.lireHoraire()) / CLOCKS_PER_SEC;
	secondes = (int)horaire;
	centieme = (int)((horaire - secondes) * 100);
	heure = secondes / 3600;
	minutes = (secondes % 3600) / 60;
	secondes = secondes % 60;
	if (sprintf_s(temps, taille, "%d:%d:%d.%d", heure, minutes, secondes, centieme) == -1)

	{
		return false;
	}
	else
	{
		return true;

	}
}

bool Ccourse::lireMeilleurTemps(int participant, char* temps, int taille)
{
	if (lesParticipant[participant].lireMeilleurTours(temps, taille) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Ccourse::lireDerniersTempsTours(int participant, char* temps, int taille)
{
	if (lesParticipant[participant].lireDernierTours(temps, taille) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Ccourse::lireNbTours(int participant)
{
	return lesParticipant[participant].lireNbTours();
}

bool Ccourse::AjoutTours(int participant)
{
	if (leChrono.getEtatChrono() == true)
	{
		lesParticipant[participant].ajouterTours(leChrono.lireHoraire());
		return true;
	}
	else
		return false;
}
