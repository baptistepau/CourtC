// Image.h: interface for the CImageEtu class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGE_H__1BC9F480_113A_4B9E_8AB6_15694E9AFAF1__INCLUDED_)
#define AFX_IMAGE_H__1BC9F480_113A_4B9E_8AB6_15694E9AFAF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <Windows.h>
class CImageEtu  
{

private:
	int Hauteur;
	int Largeur;
	byte ** TabImage;
public:
	void GetImageModifiee(byte * Donnees);
	CImageEtu(int Larg,int Haut);
	virtual ~CImageEtu();
	void Efface();
	void Remplir(byte ValCouleur);
	bool Ligne(int emplacement);
	void Bordure();
	void Damier();
};

#endif // !defined(AFX_IMAGE_H__1BC9F480_113A_4B9E_8AB6_15694E9AFAF1__INCLUDED_)
