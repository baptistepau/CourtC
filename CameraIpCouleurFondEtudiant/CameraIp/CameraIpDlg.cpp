
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
	m_ilSliderBleu = 0;
	m_iSliderRouge = 0;
	m_iSliderVert = 0;
	m_iSliderBande = 0;
}

void CCameraIpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_AXISMEDIACONTROL, mCtlCamera);
	DDX_Control(pDX, IDC_ARRETER, m_ctlArret);
	DDX_Control(pDX, IDC_DEMARRER, m_ctlDemar);
	DDX_Control(pDX, IDC_SLIDERBLEU, m_ctlSliderBleu);
	DDX_Control(pDX, IDC_SLIDERROUGE, m_ctlSliderRouge);
	DDX_Control(pDX, IDC_SLIDERVERT, m_ctlSliderVert);
	DDX_Slider(pDX, IDC_SLIDERBLEU, m_ilSliderBleu);
	DDX_Slider(pDX, IDC_SLIDERROUGE, m_iSliderRouge);
	DDX_Slider(pDX, IDC_SLIDERVERT, m_iSliderVert);
	DDX_Control(pDX, IDC_SLIDERBANDE, m_ctlSliderBande);
	DDX_Slider(pDX, IDC_SLIDERBANDE, m_iSliderBande);
	DDX_Check(pDX, IDC_MIRROIR, m_bMirroir);
	DDX_Check(pDX, IDC_REGLAGE, m_bReglage);
	DDX_Check(pDX, IDC_TAUXBLEU, m_bBleu);
	DDX_Check(pDX, IDC_TAUXROUGE, m_bRouge);
	//  DDX_Control(pDX, IDC_TAUXVERT, m_bVert);
	DDX_Check(pDX, IDC_TAUXVERT, m_bVert);
}

BEGIN_MESSAGE_MAP(CCameraIpDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_QUITTER, &CCameraIpDlg::OnBnClickedQuitter)
	ON_BN_CLICKED(IDC_DEMARRER, &CCameraIpDlg::OnBnClickedDemarrer)
	ON_BN_CLICKED(IDC_ARRETER, &CCameraIpDlg::OnBnClickedArreter)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// gestionnaires de messages pour CCameraIpDlg

BOOL CCameraIpDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// D�finir l'ic�ne de cette bo�te de dialogue. L'infrastructure effectue cela automatiquement
	//  lorsque la fen�tre principale de l'application n'est pas une bo�te de dialogue
	SetIcon(m_hIcon, TRUE);			// D�finir une grande ic�ne
	SetIcon(m_hIcon, FALSE);		// D�finir une petite ic�ne

	// TODO: ajoutez ici une initialisation suppl�mentaire
	/*********************************************************************************/
	mCtlCamera.put_MediaPassword(L"btssn2018!#$");
	mCtlCamera.put_MediaUsername(L"root");
	mCtlCamera.put_MediaURL(L"http://172.29.10.151/axis-cgi/mjpg/video.cgi");
	mCtlCamera.put_MediaType(L"mjpeg");
	mCtlCamera.put_StretchToFit(TRUE);

	/*********************************************************************************/
	// Initialisation des sliders
	int i;
	m_ctlSliderRouge.SetRange(0,255);
	for (i=0;i<=255;i+=16)
		m_ctlSliderRouge.SetTic( i);
	m_ctlSliderRouge.SetPos(0);
	m_ctlSliderVert.SetRange(0,255);
	for (i=0;i<=255;i+=16)
		m_ctlSliderVert.SetTic( i);
	m_ctlSliderVert.SetPos(0);
	m_ctlSliderBleu.SetRange(0,255);
	for (i=0;i<=255;i+=16)
		m_ctlSliderBleu.SetTic( i);
	m_ctlSliderBleu.SetPos(0);
	m_ctlSliderBande.SetRange(0,100);
	for (i=0;i<=50;i+=10)
		m_ctlSliderBande.SetTic( i);
	m_ctlSliderBande.SetPos(0);
	/*********************************************************************************/
	m_ctlDemar.ShowWindow(SW_SHOW);
	m_ctlArret.ShowWindow(SW_HIDE);
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
	OnOK();
}


void CCameraIpDlg::OnBnClickedDemarrer()
{
	mCtlCamera.Play();
	/*********************************************************************************/
	// cr�ation image pour les etudiants
	pMonImage= NULL;
	int NbEchec=0;
	long Taille;
	do 
	{
		try 
		{
			mCtlCamera.GetCurrentImage(1,&ImageCam,&Taille);
			pMonImage=new CImageEtu(((BITMAPINFOHEADER*)ImageCam.parray->pvData)->biWidth,((BITMAPINFOHEADER*)ImageCam.parray->pvData)->biHeight);
		}
		catch(COleDispatchException *e)
		{
			Sleep(1000);
			NbEchec++;
		}
	}
	while ((pMonImage== NULL)&&(NbEchec<10));
	
	if(NbEchec==10)
	{	
		// impossible de parler  la cam�ra
		MessageBox(L"Impossible d'�tablir la connexion avec la cam�ra, Veuillez v�rifier le r�seau");
		delete pMonImage;
	}
	else
	{
			SetTimer(TIMER,100,NULL);
			m_ctlDemar.ShowWindow(SW_HIDE);
			m_ctlArret.ShowWindow(SW_SHOW);
	}

}


void CCameraIpDlg::OnBnClickedArreter()
{
	KillTimer(TIMER);
	mCtlCamera.Stop();
	delete pMonImage;
	m_ctlDemar.ShowWindow(SW_SHOW);
	m_ctlArret.ShowWindow(SW_HIDE);
}


void CCameraIpDlg::OnTimer(UINT_PTR nIDEvent)
{
	UpdateData(TRUE);
	// Capture une image
	long Taille;
	mCtlCamera.GetCurrentImage(1,&ImageCam,&Taille);
	//Initialistion de l'objet Image
	pMonImage->SetImageDepart(((BYTE*)ImageCam.parray->pvData)+sizeof(BITMAPINFOHEADER));
	
	// Mirroir ?
	if(m_bMirroir)
		pMonImage->Mirroir();
	if (m_bRouge||m_bVert||m_bBleu)
	{
		if (m_bRouge)
			pMonImage->ChangeTauxRouge(m_iSliderRouge);
		
		if (m_bBleu)
			pMonImage->ChangeTauxBleu(m_ilSliderBleu);
		
		if (m_bVert)
			pMonImage->ChangeTauxVert(m_iSliderVert);
	}
	else
	{// Changement de l'arriere plan
	if(m_bReglage)
		pMonImage->EffaceArrierePlan(m_iSliderRouge,m_iSliderVert,m_ilSliderBleu,m_iSliderBande);
	else 
		pMonImage->RemplaceArrierePlan(m_iSliderRouge,m_iSliderVert,m_ilSliderBleu,m_iSliderBande);
	}
	//
	pMonImage->GetImageModifiee(((BYTE*)ImageCam.parray->pvData)+sizeof(BITMAPINFOHEADER));
	// Affichage de l'image modifi�e
	AfficheImage();
	// Lib�ration de la m�moire du variant
	VariantClear(&ImageCam);
	CDialogEx::OnTimer(nIDEvent);
}


void CCameraIpDlg::AfficheImage(void)
{
	CClientDC dc(this); // contexte de p�riph�rique
	CBitmap MonBitmap;
	CDC DCMem; 

	// Cr�ation du bitmap adapt� a la taille de la camera : dc
	MonBitmap.CreateCompatibleBitmap(&dc,((BITMAPINFOHEADER*)ImageCam.parray->pvData)->biWidth,((BITMAPINFOHEADER*)ImageCam.parray->pvData)->biHeight);
	// remplissage du bitmap avec les points de la camera
	SetDIBits(dc.m_hDC,MonBitmap,0,((BITMAPINFOHEADER*)ImageCam.parray->pvData)->biWidth,((BYTE*)ImageCam.parray->pvData)+sizeof(BITMAPINFOHEADER),(BITMAPINFO *)ImageCam.parray->pvData,DIB_RGB_COLORS);
	
	DCMem.CreateCompatibleDC(&dc);
	CBitmap * pOldBitmap=DCMem.SelectObject(&MonBitmap);
	// affichage du bitmap
	dc.SetStretchBltMode(COLORONCOLOR);
	dc.StretchBlt(0,0,640,480,&DCMem,0,0,((BITMAPINFOHEADER*)ImageCam.parray->pvData)->biWidth,((BITMAPINFOHEADER*)ImageCam.parray->pvData)->biHeight,SRCCOPY);
	//R�cup�ration de l'ancien device context
	DCMem.SelectObject(pOldBitmap);
}
