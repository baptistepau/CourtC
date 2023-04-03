#include <iostream>
#define TMAX 50
using namespace std;

void main(void)
{
    // declaration variable
    char mot[TMAX];
    int cpt;
    int i;
    int nbCar;

    cout << "Saisissez votre mot" << endl;
    cin >> mot;
    cout << "Quelle numero de lettre voulez-vous suppr" << endl;
    cin >> nbCar;
    cpt = 0;
    while (mot[cpt] != '\0')
    {
        cpt++;
    }
    i = nbCar;
    cout << i << endl;
    while (mot[cpt] != '\0')
    {
        while (i == cpt)
        {
            mot[i] = mot[i + 1];
            i++;
        }
    }
   
    cout << mot << endl;
    

}