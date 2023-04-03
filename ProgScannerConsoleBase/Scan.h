#pragma once
#include "odmxusb.h"

class CScan
{
	public:
		CScan(int Adresse);
		~CScan(void);
		void EnvoyerCommande(int couleur, int gobo, int PosX,int PosY,int Lum=255, int strobe=255);
	
	private :
		Open_USB_DMX ReseauDMX;
		int premCanal;
};

