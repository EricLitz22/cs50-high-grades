#include <cs50.h>
#include <stdio.h>

int max = 8; // only to change the maximum height easily
int height; // these to need to be here for the new function "hashes"
int i;
void hashes(void); // this is a previus declaration of a function for the compiler understands this is not an error

int main(void)
{
    do
    {
        height = get_int("Height: "); //repets the code until get a valid answer
    }
    while (height <= 0 || height > max);

    for (i = 0; i <= height; i++)
    {
        hashes();// this is a whole logic that we evolved to a function to save space   
    }
}






void hashes(void) //this whole logic is an repetition of a code of adding some hashes and spaces per line
{
    for (int j = height - i; j > 0; j--)//it needs to be inside another "for" to repeat the whole program and build the right shape
    {
        if (i > 0)
        {
            printf(" ");
        }
    }
    for (int k = 0; k < i; k++)
    {
        printf("#");
    }
    if (i > 0)
    {
        printf(" ");

        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        printf("\n");
    }
}
