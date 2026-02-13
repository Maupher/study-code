#include <stdio.h>

void stringChanger(int args, char **argp);

void main ()
{
char test[20] = "This is goood shit";
char *pInChar = &test[0];
short sStelleChar = 4;

stringChanger(sStelleChar, pInChar);

printf("%s", test);

}

void stringChanger(int args, char **argp){

    for (int i = 0; i < args; i++)
    {
        *argp++;
    }
    **argp = "4";
}


