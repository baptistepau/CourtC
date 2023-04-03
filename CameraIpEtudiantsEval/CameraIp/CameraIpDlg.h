
// CameraIpDlg.h : fichier d'en-t�te
//

#pragma once
#include "axismediacontrol.h"
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
public:
	CAxismediacontrol mCtlCamera;
	afx_msg void OnBnClickedQuitter();
	afx_msg void OnBnClickedDemarrer();
	afx_msg void OnBnClickedArreter();
//	afx_msg void OnBnClickedSnap();
//	CStatic m_ctlAFfBmp;
//	CSliderCtrl m_ctlSlider;
private :
	VARIANT ImageCam;
	CImageEtu * pMonImage;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	int m_ISlide;
//	BOOL m_bQuatre;
	BOOL m_bInvVideo;
	BOOL m_bNB;
//	BOOL m_bViseur;
//	BOOL m_bMirroir;
	void AfficheImage(void);
	CButton m_ctlArret;
	CButton m_ctlDemar;
//	int m_iEpais;
};
