
// CameraIpDlg.h : fichier d'en-tête
//

#pragma once
#include "axismediacontrol.h"
#include "Image.h"

// boîte de dialogue CCameraIpDlg
class CCameraIpDlg : public CDialogEx
{
// Construction
public:
	CCameraIpDlg(CWnd* pParent = NULL);	// constructeur standard

// Données de boîte de dialogue
	enum { IDD = IDD_CAMERAIP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Prise en charge de DDX/DDV


// Implémentation
protected:
	HICON m_hIcon;

	// Fonctions générées de la table des messages
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CAxismediacontrol mCtlCamera;
	afx_msg void OnBnClickedQuitter();
	afx_msg void OnBnClickedDemarrer();
	afx_msg void OnBnClickedArreter();
private :
	VARIANT ImageCam;
	CImageEtu * pMonImage;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void AfficheImage(void);
	CButton m_ctlArret;
	CButton m_ctlDemar;
	CSliderCtrl m_ctlSliderBleu;
	CSliderCtrl m_ctlSliderRouge;
	CSliderCtrl m_ctlSliderVert;
	int m_ilSliderBleu;
	int m_iSliderRouge;
	int m_iSliderVert;
	CSliderCtrl m_ctlSliderBande;
	int m_iSliderBande;
	BOOL m_bMirroir;
	BOOL m_bReglage;
	BOOL m_bBleu;
	BOOL m_bRouge;
//	CButton m_bVert;
	BOOL m_bVert;
};
