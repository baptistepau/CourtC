#pragma once
#include "odmxusb.h"

typedef unsigned char byte ;


class CPar
{
public:
	CPar(int Ad,Open_USB_DMX* pLiaison);
	~CPar(void);


private:
	int Adresse;
	Open_USB_DMX* pDMX;
public:
	bool ChangeCouleur(byte TauxRouge,byte TauxVert,byte TauxBleu);
	bool ChangePuiss(byte Puissance);
	bool ChangeStrobe(byte ValStrobe);
};

