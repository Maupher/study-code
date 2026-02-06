#include <stdio.h>
#include <stdbool.h>    //boolean 
#include <stdlib.h>     //system funktionen


///
/// Eingabe wird übersprungen wegen \0 im cache FIX
///
//

double EingabeEinlesen_double(int EingabeNummer);
void pause();

void main(){

    double dEingabe1 = EingabeEinlesen_double(1);
    double dEingabe2 = EingabeEinlesen_double(2);

    system("cls");
    printf("\n\n\tWählen Sie die Rechenoperation aus von 1-4:\n\t\t1 Addition +\n\t\t2 Subtraktion -\n\t\t3 Multiplikation *\n\t\t4 Division /\n\n\tIhre Auswahl: ");

    short sAuswahl;
    bool bcheck = false;
    do {  
        if ((scanf("%hd", sAuswahl) != 1) && 0 < sAuswahl < 5)
        {
            printf("Ihre Eingabe ist ungültig!");
            bcheck = false;
        }

        else bcheck = true;
        pause();

    } while (bcheck == false);

    switch (sAuswahl) {
        double dErgebnis;
        case 1: 
            dErgebnis = dEingabe1 + dEingabe2;
            break;
        case 2: 
            dErgebnis = dEingabe1 - dEingabe2;;
            break;
        case 3: 
            dErgebnis = dEingabe1 * dEingabe2;
            break;
        case 4: 
            dErgebnis = dEingabe1 / dEingabe2;
            break;
        default: 
            printf("FATAL ERROR");
            system("timeout /t 3");
            break;
    }
    printf("\n\n\n\tDas Ergebnis ist: %d", dErgebnis);
    pause();

}

double EingabeEinlesen_double(int EingabeNummer)
{
    double dEingabe;
    bool bcheck = false;
    do {  
        system("cls");
        printf("\n\tBitte geben Sie die %d. Zahl ein: ", EingabeNummer);

        if ((scanf("%lf", &dEingabe) != 1))
        {
            printf("Ihre Eingabe %d. ist ungültig!", EingabeNummer);
            bcheck = false;
        }
        else bcheck = true;
        putchar();
        pause();

    } while (bcheck == false);

    return dEingabe;
}

void pause()
{
    printf("\n\n\n\n\t");
    system("pause");
}

