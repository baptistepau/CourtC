#include <iostream>
#define TMAX 50
using namespace std;
void main(void) 
{
	char mot[TMAX];
	char car;
	int i,j;

	cout << "Entrer la chaine de carractere" << endl;
	cin >> mot;
	cout << "Quelle carractere voulez-vous suprimer" << endl;
	cin >> car;
	i = 0;
	while (mot[i] != '\0')
	{
		if (mot[i] == car) 
		{// decaler tout le reste
			j = i;
			while (mot[j]!='\0') 
			{
				mot[j] = mot[j + 1];
				j++;

			}
		}
		else
		{
			i++;
		}
	}
	cout << mot << endl;
}