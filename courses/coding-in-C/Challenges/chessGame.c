#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

bool bLayout[25][25][2]; 

void init_GUI();
void buildGrid(short size);
void gridHorizontal(short length);
void gridVertical(short length, bool color);
void gridLettering(short length);

void main() 
{

init_GUI();

}





void init_GUI()
{
    short sGrid = 8;    // max. 25 (A - Z)
    
    system("cls"); 
    printf("\n\n");

    buildGrid(sGrid);
    bool test = 0;
    
}

void buildGrid(short size)
{
    gridLettering(size);
    for (int i = 0; i < size; i++)
    {
        gridHorizontal(size);
        gridVertical(size, (i%2));      //i % 2 -> White / Black - gerade / ungerade
    }
    gridHorizontal(size);
    gridLettering(size);
}

void gridHorizontal(short length)
{
    // char cHoriz = 0x5F; // Horizontale Linie
    char cHoriz = 0x2D;
    char cSpace[] = {0x20}; // Space

    printf("\n\t");
    for (int i = 0; i < length; i++)
    {
        printf(cSpace);
        putchar(cHoriz);
        putchar(cHoriz);
    }
} 


//add Nummerierung!!
void gridVertical(short length, bool color)
{
    char cVert = 0x7C;  // Vertikale Linie
    char cBlack = 0x23; // "color" Black
    char sSpace = 0x20; // Space
    //char cSpace[] = {0x20, 0x20, 0x20}; // Space
    
    printf("\n\t");
    // for right color in der auswahl (i+color) % 2 --> wenn color 1 beginnt mit schwarz, wenn color 0 beginnt mit weiß und wechselt
    for (int i = 0; i < length; i++)
    {
        putchar(cVert);
        if ((i + color) % 2 == 0)
        {  
            for (int b = 0; b < 3; b++)
                putchar(sSpace);
        }
        else if ((i + color) % 2 == 1)
        {
            for (int b = 0; b < 3; b++)
                putchar(cBlack);
        }
    }
    putchar(cVert);
}

void gridLettering(short length)
{
    uint8_t A = 0b01000001; 
    char cSpace3[] = {0x20, 0x20, 0x20}; // Space
    char cSpace2[] = {0x20, 0x20}; // Space
    char cSpace1[] = {0x20};
    printf("\n\t");    
    printf(cSpace1);
    
    for (int i = 0; i < length; i++)
    {
        putchar(A);
        A++;
        printf(cSpace3);
    }
}
 