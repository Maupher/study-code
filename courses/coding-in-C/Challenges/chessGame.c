#include <stdio.h>
#include <stdbool.h>

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
    // char cHoriz = 0x7C; // Horizontale Linie 
    // char cVert = 0x90;  // Vertikale Linie 
    // printf("\n\t\t%c\n\t\t%c", cHoriz, cVert);
    
    for (int i = 0; i < size; i++)
    {
        printf("\n\t");
        gridHorizontal(size);
        printf("\n\t");
        gridVertical(size + 1, (i%2));      //i % 2 -> Black / White - gerade / ungerade
    }

}

void gridHorizontal(short length)
{
    char cHoriz = 0x7C; // Horizontale Linie
    char cSpace = 0x20; // Space 
    for (int i = 0; i < length; i++)
    {
        putchar(cHoriz);
        putchar(cSpace);
    }
} 

void gridVertical(short length, bool color)
{
    char cVert = 0x90;  // Vertikale Linie
    char[4] cSpace = {0x20, 0x20, 0x20}; // Space
    

    // for right color in der auswahl (i+color) % 2 --> wenn color 1 beginnt mit schwarz, wenn color 0 beginnt mit weiß und wechselt
    for (int i = 0; i < length; i++)
    {
        
        putchar(cVert);
    }
}