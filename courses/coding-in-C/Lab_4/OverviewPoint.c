#include <stdio.h>
#include <string.h>


void main()
{

    char cInput[100] = "TestThisLion";
    char *pcInp = &cInput[0];
    char *ptest = &cInput[0];

    ptest++;

    printf("\n\n");
    printf(cInput);
       printf("\n\n");
    printf("%c",*pcInp);
    printf("\n\n");
    printf("%c",*ptest);
    ptest++;
    printf("%c",*ptest);
    printf("\n\n");
    ptest++;
    printf("%c",*ptest);
       printf("\n\n");
       printf("%p",&pcInp);

}


