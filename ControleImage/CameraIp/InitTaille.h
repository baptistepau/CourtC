#pragma once


// Boîte de dialogue CInitTaille

class CInitTaille : public CDialogEx
{
	DECLARE_DYNAMIC(CInitTaille)

public:
	CInitTaille(CWnd* pParent = NULL);   // constructeur standard
	virtual ~CInitTaille();

// Données de boîte de dialogue
	enum { IDD = IDD_INIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedValide();
	int m_iNbLarg;
	int m_iNbHaut;
};
