// InitTaille.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "CameraIp.h"
#include "InitTaille.h"
#include "afxdialogex.h"


// Boîte de dialogue CInitTaille

IMPLEMENT_DYNAMIC(CInitTaille, CDialogEx)

CInitTaille::CInitTaille(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInitTaille::IDD, pParent)
{

	m_iNbLarg = 20;
	m_iNbHaut = 10;
}

CInitTaille::~CInitTaille()
{
}

void CInitTaille::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NBLARG, m_iNbLarg);
	DDX_Text(pDX, IDC_NBHAUT, m_iNbHaut);
}


BEGIN_MESSAGE_MAP(CInitTaille, CDialogEx)
	ON_BN_CLICKED(IDC_Valide, &CInitTaille::OnBnClickedValide)
END_MESSAGE_MAP()


// Gestionnaires de messages de CInitTaille




void CInitTaille::OnBnClickedValide()
{
	UpdateData(TRUE);
	if((m_iNbHaut<3)||(m_iNbHaut>10)||(m_iNbLarg<3)||(m_iNbLarg>20))
	{
		MessageBox(L"Le nombre de pixels doit être compris entre 3 et 10 en hauteur et 3 pet 20 en largeur",L"Erreur");
	}
	else 
	{
		OnOK();
	}

}
