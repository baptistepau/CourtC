// Image.h: interface for the CImageEtu class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGE_H__1BC9F480_113A_4B9E_8AB6_15694E9AFAF1__INCLUDED_)
#define AFX_IMAGE_H__1BC9F480_113A_4B9E_8AB6_15694E9AFAF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CImageEtu  
{
public:
	void ChangeCouleur(int valeur);
	void Zoom(int valeur);
	void Coin();
	void NoirBlanc();
	void GetImageModifiee(byte * Donnees);
	void InverseVideo();
	void AddCible();
	void Mirroir();
	void SetImageDepart(byte *Debut);
	CImageEtu(int Larg,int Haut);
	virtual ~CImageEtu();

private:
	int Hauteur;
	int Largeur;
	byte ** TabImage;
	byte ** TabImage2;
};

#endif // !defined(AFX_IMAGE_H__1BC9F480_113A_4B9E_8AB6_15694E9AFAF1__INCLUDED_)
