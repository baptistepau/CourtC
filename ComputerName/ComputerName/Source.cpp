#include <windows.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void main(void)
{
	char name[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD tailleName;
	DWORD masque;
	DWORD uniter;
	UINT typeDrive;
	DWORD byteCluster, nbByte, freeByte , nbclusters;
	int i;
	bool sortie = TRUE;
	char lettre;
	char disque[3]="A:";
	sortie = GetUserNameA(name, &tailleName);
	if (sortie == FALSE)
	{
		cout << "ERREUR" << endl;
	}
	else
	{
		cout << "Nom de l'utilisateur :" << name << endl;
	}
	tailleName = MAX_COMPUTERNAME_LENGTH+1;
	sortie = GetComputerNameA(name, &tailleName);
	if (sortie == FALSE)
	{
		cout << "ERREUR" << endl;
	}
	else 
	{
		cout << "Nom de l'ordinateur : " << name << endl;
	}
	//uniter = GetLogicalDrives();
	for (lettre = 'A'; lettre <= 'Z'; lettre++)
	{
		disque[0] = lettre;
		typeDrive = GetDriveTypeA(disque);
		if (typeDrive != DRIVE_UNKNOWN and typeDrive != DRIVE_NO_ROOT_DIR)
		{
			GetDiskFreeSpaceA(disque, &byteCluster, &nbByte, &freeByte, &nbclusters);
			switch (typeDrive)
			{
			case DRIVE_REMOVABLE:
				cout << "Le disque " << lettre << " est un cles usb" << endl;
				cout << freeByte << "/" << nbclusters << endl;
				break;
			case DRIVE_FIXED:
				cout << "Le disque " << lettre << " est un disque interne" << endl;
				cout << freeByte << "/" << nbclusters << endl;
				break;
			case DRIVE_REMOTE:
				cout << "Le disque " << lettre << " est un disque reseau" << endl;
				cout << freeByte << "/" << nbclusters << endl;
				break;
			case DRIVE_CDROM:
				cout << "Le disque " << lettre << " est un CDROM" << endl;
				cout << freeByte << "/" << nbclusters << endl;
				break;
			case DRIVE_RAMDISK:
				cout << "Le disque " << lettre << " est un RAM Disque" << endl;
				cout << freeByte << "/" << nbclusters << endl;
				break;
			default:
				break;
			}
		}
	}
}