#include "CPendu.h"
#include <iostream>

using namespace std;

CPendu::CPendu(char mot[], int nombreDefoisMaxi)
{
	int i = 0;
	nbLettreDuMot = 0;
	for (i = 0; i < 20; i++)
	{
		motSecret[i] = mot[i];
	}
	while (motSecret[nbLettreDuMot] != '\0')
	{
		nbLettreDuMot++;
	}
	nbCoupMaxi = nombreDefoisMaxi;
	nbCoupRestant = nbCoupMaxi;
	nbLettreTrouve = 0;
}

CPendu::~CPendu()
{

}

bool CPendu::testerCaractere(char caractere)
{
	int i = 0;
	while (motSecret[i]!='\0')
	{
		if (motSecret[i] == caractere) 
		{
			nbCoupRestant = nbCoupRestant - 1;
			nbLettreTrouve = nbLettreTrouve + 1;
			return true;	
		}
		else 
		{
			nbCoupRestant = nbCoupRestant - 1;
			return false;
		}
	}
	
}