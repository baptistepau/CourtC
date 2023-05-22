
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
	, m_csTemps(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChronoGraphDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_AFF, m_csTemps);
	DDX_Control(pDX, IDC_AFF, m_ctlAFF);
}

BEGIN_MESSAGE_MAP(CChronoGraphDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DDEMARRER, &CChronoGraphDlg::OnBnClickedDdemarrer)
	ON_BN_CLICKED(IDC_STOP, &CChronoGraphDlg::OnBnClickedStop)
	ON_BN_CLICKED(IDC_QUIT, &CChronoGraphDlg::OnBnClickedQuit)
	ON_WM_TIMER()
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
	// Changement poilce caractère affichage
	PoliceAFF.CreatePointFont(300, L"Comic sans MS", NULL);
	m_ctlAFF.SetFont(&PoliceAFF);


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



void CChronoGraphDlg::OnBnClickedDdemarrer()
{
	if (!monChrono.Start())
	{
		SetTimer(TIMER, 10, NULL);
		MessageBox(L"Impossible de lancer le chrono");
	}
}


void CChronoGraphDlg::OnBnClickedStop()
{
	if (!monChrono.Stop())
	{
		KillTimer(TIMER);
		MessageBox(L"Impossible de lancer le chrono");
	}
}


void CChronoGraphDlg::OnBnClickedQuit()
{
	OnOK();
}


void CChronoGraphDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ajoutez ici le code de votre gestionnaire de messages et/ou les paramètres par défaut des appels
	char temps[12];
	monChrono.lireTemps(temps, 12);
	m_csTemps = CString(temps);
	UpdateData(FALSE);
	CDialogEx::OnTimer(nIDEvent);
}
