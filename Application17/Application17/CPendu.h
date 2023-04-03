#pragma once
class CPendu
{
	private : 
		int nbCoupMaxi;
		char motSecret[20];
		char motTravail[20];
		char motJouer[20];
		int nbLettreDuMot;
		int nbCoupRestant;
		int nbLettreTrouve;
	public :
		CPendu(char mot[], int nombreDeFoisMaxi);
		~CPendu();
		bool testerCaractere(char caractere);
		bool cestGagner();
		int getNbCoupRestant();
		int getNbCoupJouer();
		void getMotJouer(char mot[]);
		void getMotSecret(char mot[]);

};

