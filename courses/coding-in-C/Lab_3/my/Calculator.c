#include <stdio.h>
#include <stdbool.h>


void main(){

    float fEingabe1;
    float fEingabe2;
    bool bcheck = true;

    do {  
        system("cls");
        printf("\n\tBitte geben Sie die erste Zahl ein: ");
        if ((scanf("%f", &fEingabe1) != 1))
        {
            printf("\n\tIhre Eingabe 1. ist ungültig!");
            bcheck = false;
        }
        else bcheck = true;

    } while (bcheck == false);

    do {  
        system("cls");
        printf("\n\tBitte geben Sie die zweite Zahl ein: ");
        if ((scanf("%f", &fEingabe2) != 1))
        {
            printf("Ihre Eingabe 22 ist ungültig!");
            bcheck = false;
        }
        else bcheck = true;

    } while (bcheck == false);

}