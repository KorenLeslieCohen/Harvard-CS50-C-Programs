/**
 * vigenere.c
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

// program to encrypt user string by keyword entered in command line argument
int main(int argc, string argv[])
{
    // declare variables
    int shift;
    int KeyValue;
   
    // only accept two command line arguments
    if (argc != 2)
    {
        printf("No key or incorrect key. Run program and enter single alphabetical keyword in command line.\n");
        return 1;
    }

    // capture the second command line argument as a string
    string key = argv[1]; 
    
    // iterate through the key to make sure it's alphabetical
    for (int n = 0, keylength = strlen(argv[1]); n < keylength; n++)
    {
        if ((key[n] >= '0') && (key[n] <= '9'))
        {
            printf("Sorry! You were supposed to enter a keyword with only letters.  Boohoo.\n");
            return 1;
        }
    }
    
    // get the plain text
    // doesn't pass check50 when printed - printf("Type a word to encrypt!\n");
    string PlainText = GetString();   
    
    // encrypt - iterate over the characters in string, printing each one encrypted
    for(int i = 0, j = 0, length = strlen(PlainText); i < length; i++, j++)
    {
        // start the key again if key shorter than PlainText
        if (j >= strlen(key))
        {
            j = 0;
        }
        
        // loop was "breaking" when I used "key[j]" for "A" or "a" due to the above
        // declared a variable of a different name to make the program run properly
        KeyValue = key[j]; 
        
        // skip key[j] if PlainText[i] is not an alpha character
        if (!isalpha(PlainText[i]))
        {
            j = (j - 1);
        }  
        
        // makes Aa = 0, Zz = 25 for the uppercase letters 
        if ((KeyValue >= 'A') && (KeyValue <=  'Z'))
        {
            KeyValue = (KeyValue -  'A');
        }
        
        // makes Aa = 0, Zz = 25 for the lowercase letters
        if ((KeyValue >= 'a') && (KeyValue <= 'z'))
        {
            KeyValue = (KeyValue - 'a');
        }
        
        // encryption
        shift = (PlainText[i] + KeyValue);
        
        // wrapping after Z for uppercase letters
        if (isupper(PlainText[i]) && (shift > 'Z'))
        {
            shift = (shift - 26);
        }
            
        // wrapping after z for lowercase letters
        if (islower(PlainText[i]) && (shift > 'z'))
        {
            shift = (shift - 26);
        }
            
        // test - printf("The ASCII value of %c is %d.\n\n", shift, shift);
        // test - printf("In calculating %c + %d...\n", PlainText[i], key[j]); 
        // test - printf("The value of PlainText %c is %d\n", PlainText[i], PlainText[i]);
        // test - printf("The value of key is %d\n", KeyValue); 
        
        // if character is alphabetical, print encrypted result
        if (isalpha(PlainText[i]))
        {
            printf("%c", shift);
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


