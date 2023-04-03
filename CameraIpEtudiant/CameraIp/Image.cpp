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

// Ajouter une cible
void CImageEtu::AddCible()
{
	int i, j,y,centreL,centreH,espaceL,espaceH;
	i = Largeur/2;
	for (j = 0 ; j < Hauteur; j++)
	{
		TabImage[j][i] = 255;
	}
	i = Hauteur / 2;
	for (j = 0; j < Largeur; j++) 
	{
		TabImage[i][j] = 255;
	}

	
	for (espaceL = Largeur / 10; espaceL < Largeur; espaceL += Largeur/10)
	{
		for (j = 0; j < Hauteur / 40; j++)
		{
			TabImage[(Hauteur / 2) + j][espaceL] = 255;
			TabImage[(Hauteur / 2) - j][espaceL] = 255;
		}
		
	}
	for (espaceH = Hauteur / 10; espaceH < Hauteur; espaceH += Hauteur / 10)
	{
		for (j = 0; j < Largeur / 40; j++)
		{
			TabImage[espaceH][(Largeur / 2) + j] = 255;
			TabImage[espaceH][(Largeur / 2) - j] = 255;
		}
	}
	
}

void CImageEtu::InverseVideo()
{
	int i, j;
	for (i = 0; i < Largeur; i++)
	{
		for (j = 0; j < Hauteur; j++)
		{
			TabImage[j][i] = -TabImage[j][i];
		}

	}
}

// Passer en noir et blanc
void CImageEtu::NoirBlanc()
{
	int i, j,color;
	for (i = 0; i < Largeur; i++)
	{
		for (j = 0; j < Hauteur; j++)
		{
			color = TabImage[j][i];
			if ((color <= 255) && (color >= 128))
			{
				TabImage[j][i] = 255;
			}
			else 
			{
				TabImage[j][i] = 0;
			}
				
		}
	}
}
//Image en 4
void CImageEtu::Coin()
{

}

//reglage de la luminosité
void CImageEtu::ChangeCouleur(int valeur)
{
	int ecartVal,i,j;
	ecartVal = valeur - 128;
	int verif;
	for (i = 0; i < Largeur; i++)
	{
		for (j = 0; j < Hauteur; j++)
		{
			//TabImage[j][i] += ecartVal;
			verif = TabImage[j][i] + ecartVal;
			if ((verif>255)||(verif<0))
			{
				TabImage[j][i] = 255;
			}
			else 
			{
				TabImage[j][i] += ecartVal;
			}
			
		}
	}
}
void CImageEtu::Mirroir()
{
	int i, j;
	int temp;
	for (i = 0; i < Largeur/2; i++)
	{
		for (j = 0; j < Hauteur; j++)
		{
			temp = TabImage[j][Largeur-i];
			TabImage[j][Largeur - i]=TabImage[j][i];
			TabImage[j][i] = temp;

		}
	}
}