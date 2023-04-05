#include "Ccourse.h"
#include <stdio.h>
#include <time.h>

Ccourse::Ccourse()
{
	etatCourse = false;
}

Ccourse::~Ccourse()
{

}
bool Ccourse::Demarrer()
{
	if (etatCourse == false)
	{
		if (leChrono.Start() == true)
		{
			return true;
		}	
		else
		{
			return false;
		}		
	}
	else
	{
		return false;
	}
}

bool Ccourse::Arreter()
{
	if (etatCourse == true)
	{
		if (leChrono.Stop() == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Ccourse::reset()
{
	if (etatCourse == false)
	{
		if (leChrono.Reset() == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
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
