
// CameraIpDlg.h : fichier d'en-t�te
//

#pragma once
#include"InitTaille.h"
#include "Image.h"

// bo�te de dialogue CCameraIpDlg
class CCameraIpDlg : public CDialogEx
{
// Construction
public:
	CCameraIpDlg(CWnd* pParent = NULL);	// constructeur standard

// Donn�es de bo�te de dialogue
	enum { IDD = IDD_CAMERAIP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Prise en charge de DDX/DDV


// Impl�mentation
protected:
	HICON m_hIcon;

	// Fonctions g�n�r�es de la table des messages
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private :
	void AfficheImage(void);
	CImageEtu * pMonImage;
	CInitTaille FenPar;
	byte* pData;
	int m_iEmplacement;
	int m_iCouleur;

public:
	afx_msg void OnBnClickedQuitter();
	afx_msg void OnBnClickedEffacer();
	afx_msg void OnBnClickedRemplir();
	afx_msg void OnBnClickedLigne();
	afx_msg void OnBnClickedBordure();
	afx_msg void OnBnClickedDamier();

};
