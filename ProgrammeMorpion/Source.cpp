#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
void main(void) {
    char morpion[3][3];

    int ligne, colone , de;
    char j1, j2;
    srand(time(NULL));
    // init du tableau 

    for (ligne = 0; ligne < 3; ligne++)
    {
        for (colone = 0; colone < 3; colone++)
        {
            morpion[ligne][colone] = '.';
        }
    }
    // affichage tableau
    for (ligne = 0; ligne < 3; ligne++)
    {
        for (colone = 0; colone < 3; colone++)
        {
            cout << morpion[ligne][colone];
        }
        cout << endl;
    }
    // tirage aléatoire du joueur 
    de = (rand() % 2) + 1;
    if (de == 1)
    {
        cout << "Le joueur 1 commence :" << endl;
        j1 = 'X';
        j2 = 'O';
    }
    else
    {
        cout << "Le joueur 2 commence :" << endl;
        j1 = 'O';
        j2 = 'X';
    }
    do
    {
        do
        {
            cout << "Sur quelle ligne voulez-vous commencez" << endl;
            cin >> ligne;
        } while (ligne >= 3);
        do
        {
            cout << "Sur quelle colone voulez-vous commencez" << endl;
            cin >> colone;
        } while (colone >= 3);
        
    } while (morpion[ligne][colone] != '.');
    morpion[ligne][colone] = j1;
    // affichage tableau
    for (ligne = 0; ligne < 3; ligne++)
    {
        for (colone = 0; colone < 3; colone++)
        {
            cout << morpion[ligne][colone];
        }
        cout << endl;
    }
    if (de == 1)
    {
        cout << "Au joueur 2 de jouer :" << endl;
    }
    else
    {
        cout << "Au joueur 1 de jouer :" << endl;
    }
    do 
    {
        
        do
        {
            cout << "Sur quelle ligne voulez-vous commencez " << endl;
            cin >> ligne;
        } while (ligne >= 3);
        do
        {
            cout << "Sur quelle colone voulez-vous commencez" << endl;
            cin >> colone;
        } while (colone >= 3);
    } while (morpion[ligne][colone] != '.');
   
    morpion[ligne][colone] = j2;
    // affichage tableau
    for (ligne = 0; ligne < 3; ligne++)
    {
        for (colone = 0; colone < 3; colone++)
        {
            cout << morpion[ligne][colone];
        }
        cout << endl;
    }
} 