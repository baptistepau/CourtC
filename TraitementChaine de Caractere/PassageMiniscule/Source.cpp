#include <iostream>
#define TMAX 50
using namespace std;

void main(void)
{
    // declaration variable
    char mot[TMAX];
    int cpt;
    int nb;
    char car;

    cout << "Saisissez votre mot" << endl;
    cin >> mot;
    cpt = 0;


    while (mot[cpt] != '\0')
    {
        if (mot[cpt] <= 0x5A)
        {
            mot[cpt] = mot[cpt] + 0x20;
        }
        cpt++;
    }
    cout << mot << endl;
}