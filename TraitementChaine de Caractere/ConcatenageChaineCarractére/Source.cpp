#include <iostream>
#define TMAX 50
using namespace std;

void main(void) {
    // declaration variable
    char mot1[TMAX];
    char mot2[TMAX];
    char motTotal[TMAX * 2];
    int cpt1;
    int cpt2;
    int cptCharTotal;

    cout << "Saisissez votre premier mot :" << endl;
    cin >> mot1;
    cout << "Saisissez votre deuxieme mot :" << endl;
    cin >> mot2;
    cptCharTotal = 0;
    cpt1 = 0;
    while (mot1[cpt1] != '\0')
    {
        motTotal[cptCharTotal] = mot1[cpt1];
        cpt1++;
        cptCharTotal++;
    }
    cpt2 = 0;
    while (mot2[cpt2] != '\0')
    {
        motTotal[cptCharTotal] = mot2[cpt2];
        cpt2++;
        cptCharTotal++;
    }
    motTotal[cptCharTotal++] = '\0';
    cout << motTotal << endl;
}