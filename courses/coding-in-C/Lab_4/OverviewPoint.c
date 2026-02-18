#include <stdio.h>
#include <string.h>


void main()
{

    char cInput[100] = "TestThisLion";
    char *pcInp = &cInput[0];
    char *ptest = &cInput[0];

    ptest++; // zum nächsten zeichen gehen

    printf("%s",cInput);    //ausgabe String - alles
       printf("\n\n");

    printf("%c",*pcInp);    //ausageb "initialisierte" Stelle
    printf("\n\n");

    ptest++; // zum nächsten zeichen gehen
    printf("%c",*ptest);    //ausgabe des spezifischen zeichens -> hochgezählt desgkab zweites

       printf("\n\n");
       printf("%p",&pcInp); //Ausgabe adresse

}


