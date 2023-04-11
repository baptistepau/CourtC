
// ChronoGraphDlg.cpp : fichier d'implémentation
//

#include "pch.h"
#include "framework.h"
#include "ChronoGraph.h"
#include "ChronoGraphDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// boîte de dialogue de CChronoGraphDlg



CChronoGraphDlg::CChronoGraphDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHRONOGRAPH_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChronoGraphDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CChronoGraphDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_STN_CLICKED(IDC_TEMPS, &CChronoGraphDlg::OnStnClickedTemps)
	ON_BN_CLICKED(IDC_QUIT, &CChronoGraphDlg::OnBnClickedQuit)
END_MESSAGE_MAP()


// gestionnaires de messages de CChronoGraphDlg

BOOL CChronoGraphDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Définir l'icône de cette boîte de dialogue.  L'infrastructure effectue cela automatiquement
	//  lorsque la fenêtre principale de l'application n'est pas une boîte de dialogue
	SetIcon(m_hIcon, TRUE);			// Définir une grande icône
	SetIcon(m_hIcon, FALSE);		// Définir une petite icône

	// TODO: ajoutez ici une initialisation supplémentaire

	return TRUE;  // retourne TRUE, sauf si vous avez défini le focus sur un contrôle
}

// Si vous ajoutez un bouton Réduire à votre boîte de dialogue, vous devez utiliser le code ci-dessous
//  pour dessiner l'icône.  Pour les applications MFC utilisant le modèle Document/Vue,
//  cela est fait automatiquement par l'infrastructure.

void CChronoGraphDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contexte de périphérique pour la peinture

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrer l'icône dans le rectangle client
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dessiner l'icône
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Le système appelle cette fonction pour obtenir le curseur à afficher lorsque l'utilisateur fait glisser
//  la fenêtre réduite.
HCURSOR CChronoGraphDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChronoGraphDlg::OnStnClickedTemps()
{
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
}


void CChronoGraphDlg::OnBnClickedQuit()
{
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
}
