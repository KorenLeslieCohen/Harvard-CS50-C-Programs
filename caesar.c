/**
 * caesar.c
 *
 * Koren Leslie Cohen
 *
 * Takes user input and encrypts it.
 *
 *  Usage: ./asciimath key
 */

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// encrypt user's word by number in command line 
int main(int argc, string argv[])
{
    // declare variables
    int key;
    int result;
   
    // only accepting two command line arguments - key and string of plaintext
    if (argc != 2)
    {
        printf("You didn't enter a key.  Please run program and enter a key when you run.\n");
        return 1;
    }
    
    // get the plain text
    string PlainText = GetString();

    // convert the string/second command line argument (number) to an integer using atoi  
    key = atoi(argv[1]);
    
    // if key is greater than or equal to 26, we need to modulo 26 so it wraps back to Aa after Za
    if (key >= 26)
    {
        key = (key % 26);
    }

    // encrypt - iterate over the characters in string, printing each one one at a time
    for(int i = 0, length = strlen(PlainText); i < length; i++)
    {
        // test - printf("In calculating %c + %d...\n", PlainText[i], key);
            
        // encryption
        result = (PlainText[i] + key);
            
        // wrapping after Z for uppercase letters
        if (isupper(PlainText[i]) && (result > 'Z'))
        {
            result = (result - 26);
        }
            
        // wrapping after z for lowercase letters
        if (islower(PlainText[i]) && (result > 'z'))
        {
            result = (result - 26);
        }
            
        // test - printf("The ASCII value of %c is %d.\n\n", result, result);

        // if character is alphabetical, print encrypted result
        if (isalpha(PlainText[i]))
        {
            printf("%c", result);
        }
         
       // if non-alphabetical character, print as is   
        else
        {
            printf("%c", PlainText[i]);
        }
            
    }
    
    printf("\n");
    return 0;
}








