#include <cs50.h>
#include <stdio.h>

int height;
int max = 8; // it's declarated here to someone changes the maximum height easily
int i;
void hashes(void); // the program need to know the code that we created
int main(void)
{
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height > max);
    
    if (height > 0 && height <= max)
    {
        for (i = 0; i <= height; i++)
        {
            hashes(); //this part it's a new code
        }
    }
    
}

void hashes(void) // here we create a code to substitute this all due to main code get smaller
{
    for (int k = height - i ; k > 0; k--)
    {
        if (i > 0)
        {
            printf(" ");
        }
    }
    for (int j = 0; j < i; j++)
    {
        printf("#");
    }
    if (i > 0)
    {
        printf("\n");
    } 
    
}
