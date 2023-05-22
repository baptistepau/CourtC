#include "pch.h"
#include "CChrono.h"
#include <time.h>
#include <stdio.h>
#include <iostream>

using namespace std;

CChrono::CChrono()
{
	etat = false;
	clockStart = 0;
	clockStop = 0;
}
CChrono::~CChrono()
{

}
bool CChrono::Start()
{
	if (etat == false)
	{
		clockStart = clock();
		etat = true;
		return true;
	}
	else
	{
		return false;
	}
}
	
bool CChrono::Stop()

{
	if (etat == true)
	{
		clockStop = clock();
		etat = false;
		return true;
	}
	else 
	{
		return false;
	}
	
}
bool CChrono::Reset()
{
	if (etat == false) 
	{
		clockStart = 0;
		clockStop = 0;
		return true;
	}
	else 
	{
		return false;
	}
}
void CChrono::lireTemps(unsigned short* h, int* mn, int* s, int* c)
{
	int secondes, iCentiemes;
	float fCentieme;
	if (etat == true)
	{
		fCentieme = (float)( clock() - clockStart) / CLOCKS_PER_SEC;
	}
	else
	{
		fCentieme = (float)(clockStop - clockStart) / CLOCKS_PER_SEC;
	}
	secondes = (int)fCentieme;
	iCentiemes = (int)((fCentieme - secondes) * 100);
	*h = secondes / 3600;
	*mn = (secondes % 3600) / 60;
	*s = secondes % 60;
	*c = iCentiemes;

}
bool CChrono::lireTemps(char* temp, int taille)
{
	int secondes;
	int minutes, heures, iCentiemes;
	float fCentieme;

	if (etat == true)
	{
		fCentieme = (float)(clock() - clockStart) / CLOCKS_PER_SEC;
	}
	else
	{
		fCentieme = (float)(clockStop - clockStart) / CLOCKS_PER_SEC;

	}
	secondes = (int)fCentieme;
	iCentiemes = (int)((fCentieme - secondes) * 100);
	heures = secondes / 3600;
	minutes = (secondes % 3600) / 60;
	secondes = secondes % 60;
	if (sprintf_s(temp, taille,"%d:%d:%d.%d", heures, minutes, secondes, iCentiemes)==-1)
	
	{
		return false;
	}
	else
	{
		return true;

	}
}