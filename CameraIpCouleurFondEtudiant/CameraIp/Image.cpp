// Image.cpp: implementation of the CImageEtu class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Image.h"
#include <fstream>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
using namespace std;

CImageEtu::CImageEtu(int Larg,int Haut)
{
	int i,j,k;
	//Mise à jour attributs
	Largeur=Larg;
	Hauteur=Haut;
	BITMAPFILEHEADER EnteteFichier;
	BITMAPINFOHEADER EnteteBMP;
	ifstream FichBinIn ;			// Pour lire

	//Allocation d'un tableau 3 dimensions pour contenir l'image en couleurs
	TabImage=new byte**[Hauteur];
	for(i=0;i<Hauteur;i++)
		TabImage[i]=new byte*[Largeur];
	for(i=0;i<Hauteur;i++)
		for(j=0;j<Largeur;j++)
			TabImage[i][j]=new byte[3];
	//Allocation d'un tableau 3 dimensions pour contenir la photo en couleurs
	TabPhoto=new byte**[Hauteur];
	for(i=0;i<Hauteur;i++)
		TabPhoto[i]=new byte*[Largeur];
	for(i=0;i<Hauteur;i++)
		for(j=0;j<Largeur;j++)
			TabPhoto[i][j]=new byte[3];
	// Chargement de la photo dans le tableau
	
	FichBinIn.open("FondDesert.bmp",ios ::binary);//|ios::ate) ;	
	//test si l’ouverture s’est bien passée.
	if(FichBinIn.fail())
	{
		// erreur chargement fichier
			for(i=0;i<Hauteur;i++)
				for(j=0;j<Largeur;j++)
					for (k=0;k<3;k++)
						TabPhoto[i][j][k]=255;
	
	}
	else
	{
		// recuperation entete fichier pour connaitre l'endroit ou commence l'image (avec l'ofset)
		FichBinIn.read((char*)&EnteteFichier,sizeof(BITMAPFILEHEADER)) ;
		if( EnteteFichier.bfType==0x4D42)
		{
			// recuperation entete Bitmap pour connaitre les caractéristique de l'image (ca sert pas pour l'instant)
			FichBinIn.read((char*)&EnteteBMP ,sizeof(BITMAPINFOHEADER)) ;
			
			// remplissage du tableau
			for(i=0;i<Hauteur;i++)
				for(j=0;j<Largeur;j++)
					for (k=0;k<3;k++)		
						FichBinIn.read((char*)(TabPhoto[i][j]+k),1) ;
		}
		else
		{
			//Erreur fichier non BMP
			for(i=0;i<Hauteur;i++)
				for(j=0;j<Largeur;j++)
					for (k=0;k<3;k++)
						TabPhoto[i][j][k]=255;
		}

	}
	
}

CImageEtu::~CImageEtu()
{

	int i,j;
	// Destruction du tableau dynamique
	for(i=0;i<Hauteur;i++)
		for(j=0;j<Largeur;j++)
			delete[] TabImage[i][j];
	for(i=0;i<Hauteur;i++)
		delete[] TabImage[i];
 	delete[] TabImage;
	// Destruction du tableau dynamique
	for(i=0;i<Hauteur;i++)
		for(j=0;j<Largeur;j++)
			delete[] TabPhoto[i][j];
	for(i=0;i<Hauteur;i++)
		delete[] TabPhoto[i];
 	delete[] TabPhoto;

}

void CImageEtu::SetImageDepart(byte *Debut)
{
	int i,j,k;
	// Recopie de l'image dans le tableau
	for(i=0;i<Hauteur;i++)
		for(j=0;j<Largeur;j++)
			for (k=0;k<3;k++)
			TabImage[i][j][k]=Debut[i*Largeur*3+j*3+k];

}

void CImageEtu::GetImageModifiee(byte *Donnees)
{
	int i,j,k;
	// Recopie de l'image modifiée vers un flux couleur
	for(i=0;i<Hauteur;i++)
		for(j=0;j<Largeur;j++)
			for (k=0;k<3;k++)
				Donnees[i*Largeur*3+j*3+k]=TabImage[i][j][k];
}


//effacement du fond
void CImageEtu::EffaceArrierePlan(int TauxRouge,int TauxVert,int TauxBleu,int bande)
{

}

void CImageEtu::RemplaceArrierePlan(int TauxRouge,int TauxVert,int TauxBleu,int bande)
{

}

void CImageEtu::Mirroir()
{
	int i, j,k;
	int temp;
	for (i = 0; i < Largeur / 2; i++)
	{
		for (j = 0; j < Hauteur; j++)
		{
			for (k = 0; k < 3; k++)
			{
				temp = TabImage[j][Largeur - i-1][k];
				TabImage[j][Largeur - i-1][k] = TabImage[j][i][k];
				TabImage[j][i][k] = temp;
			}

		}
	}
}
void CImageEtu::ChangeTauxRouge(int TauxRouge)
{
	int i, j;
	for (i = 0; i < Largeur; i++)
	{
		for (j = 0; j < Hauteur; j++) 
		{
			TabImage[j][i][2] = TabImage[j][i][2] * TauxRouge / 100;
		}
	}

}
void CImageEtu::ChangeTauxVert(int TauxVert)
{
	int i, j;
	for (i = 0; i < Largeur; i++)
	{
		for (j = 0; j < Hauteur; j++)
		{
			TabImage[j][i][1] = TabImage[j][i][1] * TauxVert / 100;
		}
	}

}
void CImageEtu::ChangeTauxBleu(int TauxBleu)
{
	int i, j;
	for (i = 0; i < Largeur; i++)
	{
		for (j = 0; j < Hauteur; j++)
		{
			TabImage[j][i][0] = TabImage[j][i][0] * TauxBleu / 100;
		}
	}
}