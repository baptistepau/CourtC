
// CameraIp.h�: fichier d'en-t�te principal pour l'application PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'stdafx.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"		// symboles principaux


// CCameraIpApp�:
// Consultez CameraIp.cpp pour l'impl�mentation de cette classe
//

class CCameraIpApp : public CWinApp
{
public:
	CCameraIpApp();

// Substitutions
public:
	virtual BOOL InitInstance();

// Impl�mentation

	DECLARE_MESSAGE_MAP()
};

extern CCameraIpApp theApp;