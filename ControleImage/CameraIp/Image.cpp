// Image.cpp: implementation of the CImageEtu class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Image.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CImageEtu::CImageEtu(int Larg,int Haut)
{
	int i;
	//Mise à jour attributs
	Largeur=Larg;
	Hauteur=Haut;
	
	//Allocation d'un tableau 2 dimensions pour contenir l'image	
	TabImage=new byte*[Hauteur];
	for(i=0;i<Hauteur;i++)
		TabImage[i]=new byte[Largeur];
}

CImageEtu::~CImageEtu()
{
	int i;
	// Destruction du tableau dynamique
	for(i=0;i<Hauteur;i++)
		delete[] TabImage[i];
 	delete[] TabImage;
}


void CImageEtu::GetImageModifiee(byte *Donnees)
{
	int i,j,index=0,bourrage,ajout;
	// Recopie de l'image modifiée vers un flux couleur
	//calcul du bourrage
	bourrage=(Largeur%4);
	for(i=0;i<Hauteur;i++)
	{
		for(j=0;j<Largeur;j++)
		{
			Donnees[index++]=TabImage[i][j];
			Donnees[index++]=TabImage[i][j];
			Donnees[index++]=TabImage[i][j];
			
		}
		//bourrage de fin de ligne
		for(ajout=0;ajout<bourrage;ajout++)
				Donnees[index++]=100;
	}
}

// mettre toute l'image a blanc
void CImageEtu::Efface()
{
}



bool CImageEtu::Ligne(int nombre)
{
	/*
	* 
	TabImage[0][0] = 0;
	return true;
	*/
	int ecart, i, j;
	
	
	if (nombre < Largeur)
	{
		ecart = Largeur / (nombre+1);
		//ecart = 0;
		i = ecart;
		while(i < Largeur)
		{
			for (j = 0; j < Hauteur; j++)
			{
				TabImage[j][i] = 0;
			}
			i += ecart;
		}
		return true;
	}
	else
	{
		return false;
	}

}


