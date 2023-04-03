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
	//Allocation d'un tableau 2 dimensions pour contenir l'image 2	
	TabImage2=new byte*[Hauteur];
	for(i=0;i<Hauteur;i++)
		TabImage2[i]=new byte[Largeur];


}

CImageEtu::~CImageEtu()
{

	int i;
	// Destruction du tableau dynamique
	for(i=0;i<Hauteur;i++)
		delete[] TabImage[i];
 	delete[] TabImage;

	// Destruction du tableau dynamique 2
	for(i=0;i<Hauteur;i++)
		delete[] TabImage2[i];
 	delete[] TabImage2;
}

void CImageEtu::SetImageDepart(byte *Debut)
{
	int i,j;
	// Recopie de l'image dans le tableau en la passant en nuances de gris
	for(i=0;i<Hauteur*3;i+=3)
		for(j=0;j<Largeur*3;j+=3)
			TabImage[i/3][j/3]=(Debut[i*Largeur+j]+Debut[i*Largeur+j+1]+Debut[i*Largeur+j+2])/3;

}

void CImageEtu::GetImageModifiee(byte *Donnees)
{
	int i,j;
	// Recopie de l'image modifiée vers un flux couleur
	for(i=0;i<Hauteur*3;i+=3)
		for(j=0;j<Largeur*3;j+=3)
		{
			Donnees[i*Largeur+j]=TabImage[i/3][j/3];
			Donnees[i*Largeur+j+1]=TabImage[i/3][j/3];
			Donnees[i*Largeur+j+2]=TabImage[i/3][j/3];
		}
}

// Faire un Zoom
void CImageEtu::Zoom()
{
	int i, j,y,k, newHauteur, newLargeur;
	newHauteur = (Hauteur / 4) + (Hauteur / 2);
	newLargeur = (Largeur / 4) + (Largeur / 2);
	
	for (i = Largeur / 4; i < newLargeur; i++)
	{
		for (j = Hauteur / 4; j < newHauteur; j++)
		{
			TabImage2[j][i] = TabImage[j][i];
		}
	}
	for (i = Largeur / 4; i < Hauteur / 4; i++)
	{
		for (j = Hauteur / 4; j < Hauteur / 4; j++)
		{
			TabImage2[j*2][i*2]
		}
	}
	for (i = 0; i < Largeur; i++)
	{
		for (j = 0; j < Hauteur; j++)
		{
			TabImage[j][i] = TabImage2[j][i];			
		}
	}


}

// Modifier en niveaux de gris
void CImageEtu::NiveauxGris()
{
	int i, j, valeurPixel;
	for (i = 0; i < Largeur; i++)
	{
		for (j = 0; j < Hauteur; j++)
		{
			valeurPixel = TabImage[j][i];
			if ((valeurPixel >= 0) && (valeurPixel <= 63))
			{
				TabImage[j][i] = 0;
			}
			else 
			{
				if ((valeurPixel >= 64) && (valeurPixel <= 127))
				{
					TabImage[j][i] = 75;
				}
				else 
				{
					if ((valeurPixel >= 128) && (valeurPixel <= 191))
					{
						TabImage[j][i] = 150;
					}
					else {
						TabImage[j][i] = 255;
					}
				}

			}
		}
	}

}
