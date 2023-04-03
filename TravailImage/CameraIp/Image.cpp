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
	int i, j;
	for (i = 0; i < Largeur; i++)
	{
		for (j = 0; j < Hauteur; j++)
		{
			TabImage[j][i] = 255 ;
		}
	}

}

void CImageEtu::Remplir(byte ValCouleur)
{
	int i = 0, j = 0 ;
	for (i = 0; i < Largeur; i++)
	{
		for (j = 0; j < Hauteur; j++)
		{
			TabImage[j][i] = ValCouleur;
		}
	}
}

bool CImageEtu::Ligne(int emplacement)
{
	int i,couleur;
	if (Hauteur < emplacement)
	{
		return false;
	}
	else
	{
		if (TabImage[(Hauteur-1)/2][(Largeur - 1) / 2] == 0)
			couleur = 255;
		else
			couleur = 0;
		for (i = 0; i < Largeur; i++)
		{
			TabImage[emplacement][i] = couleur;
		}
		return true;
	}
		
	
}

void CImageEtu::Bordure()
{
	int i;
	int width, height;
	int color;
	if (TabImage[0][0] == 0)
	{
		color = 255;
	}
	else
	{
		color = 0;
	}
	for (i = 0; i < Largeur; i++)
	{
		TabImage[0][i] = color;
		TabImage[Hauteur - 1][i] = color;
	}
	for (i = 0; i < Hauteur; i++)
	{
		TabImage[i][0] = color;
		TabImage[i][Largeur-1] = color;
	}
	width = 0;
	height = 0;
	for (i = 1; i < Hauteur; i++)
	{	
		TabImage[height][width] = color;
		width++;
		height++;
	}

}

void CImageEtu::Damier()
{
	int i,j;
	for (i = 0; i < Hauteur; i += 2)
	{
		for (j = 0; j < Largeur; j += 2)
		{
			TabImage[i][j] = 0;
		}
	}
	for (i = 1; i < Hauteur; i += 2)
	{
		for (j = 1; j < Largeur; j += 2)
		{
			TabImage[i][j] = 0;
		}
	}

}
