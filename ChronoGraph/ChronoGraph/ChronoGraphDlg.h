
// ChronoGraphDlg.h : fichier d'en-tête
//

#pragma once
#include"CChrono.h"

// boîte de dialogue de CChronoGraphDlg
class CChronoGraphDlg : public CDialogEx
{
// Construction
public:
	CChronoGraphDlg(CWnd* pParent = nullptr);	// constructeur standard

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHRONOGRAPH_DIALOG };
#endif

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
	afx_msg void OnBnClickedDdemarrer();
	afx_msg void OnBnClickedStop();
private:
	CChrono monChrono;
	CString m_csTemps;
public:
	afx_msg void OnBnClickedQuit();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CStatic m_ctlAFF;
	CFont PoliceAFF;
};
