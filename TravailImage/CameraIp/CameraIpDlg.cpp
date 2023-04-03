
// CameraIpDlg.cpp : fichier d'impl�mentation
//

#include "stdafx.h"
#include "CameraIp.h"
#include "CameraIpDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// bo�te de dialogue CCameraIpDlg

CCameraIpDlg::CCameraIpDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCameraIpDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//  m_ISlide = 0;
	m_iCouleur = 0;
	m_iEmplacement = 0;
}

void CCameraIpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_COUL, m_iCouleur);
	DDX_Text(pDX, IDC_EMPL, m_iEmplacement);
}

BEGIN_MESSAGE_MAP(CCameraIpDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_QUITTER, &CCameraIpDlg::OnBnClickedQuitter)
	ON_BN_CLICKED(IDC_EFFACER, &CCameraIpDlg::OnBnClickedEffacer)
	ON_BN_CLICKED(IDC_BORDURE, &CCameraIpDlg::OnBnClickedBordure)
	ON_BN_CLICKED(IDC_DAMIER, &CCameraIpDlg::OnBnClickedDamier)
	ON_BN_CLICKED(IDC_LIGNE, &CCameraIpDlg::OnBnClickedLigne)
	ON_BN_CLICKED(IDC_REMPLIR, &CCameraIpDlg::OnBnClickedRemplir)
END_MESSAGE_MAP()


// gestionnaires de messages pour CCameraIpDlg

BOOL CCameraIpDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// D�finir l'ic�ne de cette bo�te de dialogue. L'infrastructure effectue cela automatiquement
	//  lorsque la fen�tre principale de l'application n'est pas une bo�te de dialogue
	SetIcon(m_hIcon, TRUE);			// D�finir une grande ic�ne
	SetIcon(m_hIcon, FALSE);		// D�finir une petite ic�ne
	// fenetre parametrage
	FenPar.DoModal();
	// cr�ation de l'image �tudiants � la bonne taille
	pMonImage=new CImageEtu(FenPar.m_iNbLarg, FenPar.m_iNbHaut);

	// zone de donn�es
	// calcul de la zone de donn�es
	int ajout=0;
	if ((FenPar.m_iNbLarg*3)%4!=0)
		ajout=1;
	int nbDWordlarg=(FenPar.m_iNbLarg*3)/4+ajout;
	pData=new byte[nbDWordlarg*4*FenPar.m_iNbHaut*3];
	return TRUE;  // retourne TRUE, sauf si vous avez d�fini le focus sur un contr�le
}

// Si vous ajoutez un bouton R�duire � votre bo�te de dialogue, vous devez utiliser le code ci-dessous
//  pour dessiner l'ic�ne. Pour les applications MFC utilisant le mod�le Document/Vue,
//  cela est fait automatiquement par l'infrastructure.

void CCameraIpDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contexte de p�riph�rique pour la peinture

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrer l'ic�ne dans le rectangle client
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dessiner l'ic�ne
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Le syst�me appelle cette fonction pour obtenir le curseur � afficher lorsque l'utilisateur fait glisser
//  la fen�tre r�duite.
HCURSOR CCameraIpDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCameraIpDlg::OnBnClickedQuitter()
{
	delete pData;
	OnOK();
}



void CCameraIpDlg::AfficheImage(void)
{
	CClientDC dc(this); // contexte de p�riph�rique
	CBitmap MonBitmap;
	CDC DCMem; 
	BITMAPINFO info;
	CRect rect;
	GetClientRect(&rect);

	// recup�ration de l'image
	pMonImage->GetImageModifiee(pData);
	// pr�paration du BMP
	info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER); // Size of structure
	info.bmiHeader.biWidth =FenPar.m_iNbLarg; // Bitmaps width in pixels
	info.bmiHeader.biHeight = FenPar.m_iNbHaut; // Bitmaps height n pixels
	info.bmiHeader.biPlanes = 1; // Number of planes in the image
	info.bmiHeader.biBitCount = 24; // The number of bits per pixel
	info.bmiHeader.biCompression = BI_RGB; // The type of compression used
	info.bmiHeader.biSizeImage = 0; // The size of the image in bytes
	info.bmiHeader.biXPelsPerMeter = 0; // Horizontal resolution
	info.bmiHeader.biYPelsPerMeter = 0; // Veritical resolution
	info.bmiHeader.biClrUsed = 0; // Number of colors actually used
	info.bmiHeader.biClrImportant = 0; // Colors most important
	
	// Cr�ation du bitmap adapt� a la taille de l'image : dc
	MonBitmap.CreateCompatibleBitmap(&dc,FenPar.m_iNbLarg, FenPar.m_iNbHaut);
	// remplissage du bitmap avec les points de la camera
	SetDIBits(dc.m_hDC,MonBitmap,0,FenPar.m_iNbLarg,pData,&info,DIB_RGB_COLORS);
	//int reussi=SetBitmapBits(MonBitmap,(DWORD)(FenPar.m_iNbLarg*FenPar.m_iNbHaut*9),(void*)pData);

	DCMem.CreateCompatibleDC(&dc);
	CBitmap * pOldBitmap=DCMem.SelectObject(&MonBitmap);
	// affichage du bitmap
	dc.SetStretchBltMode(COLORONCOLOR);
	
	dc.StretchBlt(0,0,rect.Width()/2,rect.Height(),&DCMem,0,0,FenPar.m_iNbLarg, FenPar.m_iNbHaut,SRCCOPY);
	//R�cup�ration de l'ancien device context
	DCMem.SelectObject(pOldBitmap);
}


void CCameraIpDlg::OnBnClickedEffacer()
{
	pMonImage->Efface();
	AfficheImage();	
}

void CCameraIpDlg::OnBnClickedRemplir()
{
	UpdateData(TRUE);
	if(m_iCouleur<0||m_iCouleur>255)
		MessageBox(L"Cette valeur est impossible",L"Erreur");
	else
	{
		pMonImage->Remplir(m_iCouleur);
		AfficheImage();	
	}
}

void CCameraIpDlg::OnBnClickedLigne()
{
		UpdateData(TRUE);
	if(!(pMonImage->Ligne(m_iEmplacement)))
		MessageBox(L"Impossible de dessiner une ligne � cet endroit",L"Erreur");
	else
	{
		AfficheImage();	
	}
}

void CCameraIpDlg::OnBnClickedBordure()
{
	pMonImage->Bordure();
	AfficheImage();	
}
void CCameraIpDlg::OnBnClickedDamier()
{
	pMonImage->Damier();
	AfficheImage();
}





