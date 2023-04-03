#include <stdio.h>
#include <Windows.h>

#define MAX 4 
#define HAUTEUR 7

void main(void)
{
    float mesure[MAX];
    int i, j ;
    float mediane, mesureCapteur, temp ;

    for (i = 0; i < MAX; i++)
    {
        printf("Ecriver la valeur : ");
        scanf_s("%3f", &mesureCapteur);
        if (mesureCapteur == -1)
        {
            
        }

        if (HAUTEUR == 0)
        {
            mesure[i] = mesureCapteur;
        }
        else
        {
            mesure[i] = HAUTEUR - mesureCapteur;
        }
        
        Sleep(100);
    }
    for (i = MAX - 1; i >= 1; i--)
    {
        for (j= 0; j <= i-1; j++)
        {
            if (mesure[i] < mesure[j])
            {
                temp = mesure[i];
                mesure[i] = mesure[j];
                mesure[j] = temp;
            }
        }
    }
    printf("\nAffichage tableau : \n");
    for (i = 0; i < MAX; i++)
    {
        
        printf("case %i = %.1f\n", i, mesure[i]);
    }
    
    if (MAX % 2 == 0)
    {
        mediane = (mesure[(MAX + 1) / 2] + mesure[(MAX - 1) / 2]) / 2;
    }
    else
    {
        mediane = mesure[MAX / 2];
    }
    
    printf("\nLa median est de %.2f\n", mediane);
        
}
