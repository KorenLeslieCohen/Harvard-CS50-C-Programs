/**
 * mario.c
 *
 * Koren Leslie Cohen
 *
 * Creates a Mario Pyramid.
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{

    // declaring my variables
    int height;
    int all_rows;
    int space;
    int hash;

    // prompts user for integer until integer is 0 to 23
    do
    {
        printf("Welcome to Mario! Please choose a number from 0 to 23:");
        height = GetInt();
    }
    while ((height < 0) || (height > 23));
    
    // this is the loop that will create the number of rows in the pyramid entered by the usert
    for (all_rows = 1; all_rows <= height; all_rows++) 
    {
        for (space = (height - all_rows); space > 0; space--)
        {
            printf(" "); 
        }
          
        for (hash = 1; hash <= (all_rows + 1); hash++)
        {   
            printf("#"); 
        }
        
        ./vigeprintf("\n");
    }
    return 0;
}


