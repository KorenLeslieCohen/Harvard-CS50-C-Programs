/**
 * greedy.c
 *
 * Koren Leslie Cohen
 *
 * Counts the minimum number of coins needed for change.
 */

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // declare variables
    float change_float;
    int change, coins, quarter, dime, nickel, penny;
    coins = 0;
    quarter = 25;
    dime = 10;
    nickel = 5;
    penny = 1;

    // get user input to determine how much change is owed
    do
    {
        printf("How much change is owed? ");
        change_float = GetFloat();
    }
    while (change_float < 0);

    // convert to integer
    change = (int)(change_float * 100);
    
    // round
    double round(double change);

    // loops to count the coins
    while (change >= quarter)
    {
        coins = (coins + 1);
        change = (change - quarter);
    }

    // test: printf("Number of coins used after quarters: %d\n", coins);
    // test: printf("Amount of change left after quarters: %d\n", change);

    while (change >= dime)
    {
        coins = (coins + 1);
        change = (change - dime);
    }

    // test: printf("Number of coins used after dimes: %d\n", coins);
    // test: printf("Amount of change left after dimes: %d\n", change);

    while (change >= nickel)
    {
        coins = (coins + 1);
        change = (change - nickel);
    }

    // test: printf("Number of coins used after nickels: %d\n", coins);
    // test: printf("Amount of change left after nickels: %d\n", change);

    while (change >= penny)
    {
        coins = (coins + 1);
        change = (change - penny);
    }

    // min number of coins used
    printf("%d\n", coins);

    return 0;
}
