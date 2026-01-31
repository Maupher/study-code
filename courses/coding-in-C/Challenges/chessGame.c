#include <stdio.h>
#include <stdbool.h>

bool bLayout[25][25][2]; 

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
    
    for (int i = 0; i < size; i++)
    {
        printf("\n\t");
        gridHorizontal(size);
        printf("\n\t");
        gridVertical(size + 1, (i%2));      //i % 2 -> White / Black - gerade / ungerade
    }
    gridHorizontal(size);
}

void gridHorizontal(short length)
{
    char cHoriz = 0x7C; // Horizontale Linie
    char cSpace[] = {0x20}; // Space

    for (int i = 0; i < length; i++)
    {
        printf(cSpace);
        putchar(cHoriz);
    }
} 

void gridVertical(short length, bool color)
{
    char cVert = 0x90;  // Vertikale Linie
    char cBlack = 0x23; // "color" Black
    char cSpace[] = {0x20, 0x20, 0x20}; // Space
    
    // for right color in der auswahl (i+color) % 2 --> wenn color 1 beginnt mit schwarz, wenn color 0 beginnt mit weiß und wechselt
    for (int i = 0; i < length; i++)
    {
        putchar(cVert);
        if ((i + color) % 2 == 0)
            printf(cSpace);
        else 
            printf(" %c ", cBlack);
    }
}