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
	void RemplaceArrierePlan(int TauxRouge,int TauxVert,int TauxBleu,int bande);
	void EffaceArrierePlan(int TauxRouge,int TauxVert,int TauxBleu,int bande);
	void GetImageModifiee(byte * Donnees);
	void Mirroir();
	void ChangeTauxRouge(int TauxRouge);
	void ChangeTauxVert(int TauxVert);
	void ChangeTauxBleu(int TauxBleu);
	void SetImageDepart(byte *Debut);
	CImageEtu(int Larg,int Haut);
	virtual ~CImageEtu();

private:
	int Hauteur;
	int Largeur;
	byte *** TabImage;
	byte *** TabPhoto;
};

#endif // !defined(AFX_IMAGE_H__1BC9F480_113A_4B9E_8AB6_15694E9AFAF1__INCLUDED_)
