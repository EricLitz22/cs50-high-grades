#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main()
{
    int cash;

    do
    {
        float num = get_float("Change owed: ");
        cash = round(num * 100);// fit any number as an integer
    }
    while (cash <= 0);

    int quarters = cash / 25; // get the amount of coins 
    int dimes = (cash % 25) / 10;
    int nickels = ((cash % 25) % 10) / 5;
    int pennies = ((cash % 25) % 10) % 5; // here its verified if there is some rest
    int coins = quarters + dimes + nickels + pennies;

    printf("%d\n", coins); //then add all coins in one
}
