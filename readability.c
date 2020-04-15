#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

float letters = 0.00;
float sentences = 0.00;
float words = 1.00; // starts as 1 cause it doesn't count the first word
int verifier = 0;// verifier work to change words to 0 if there're not letters

float readability(string x);
int round_up(float y); // round_up its a function to round a number + 1 starting by n.38


int main(void)
{
   
    
    string text = get_string("Text: "); 

    float index = round_up(readability(text));
    
    // all this bellow is to determinate the Index of the text
    
    if (index <= 16 && index > 0)  
    {
        printf("Grade %d\n", (int) index);
    }
    
    else if (index == 0) 
    {
        printf("Grade 1\n");
    }
    
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    
    else
    {
        printf("Before Grade 1\n");
    }
   
    return 0; // determinate the program was finished
}



float readability(string x)
{
    for (int j = 0; j <= strlen(x); j++)
    {
        if (x[j] == 33 || x[j] == 46 || x[j] == 63) // counts 1 every time it gets a pontuation
        {
            sentences++;
        }
        
        else if ((x[j] > 96 && x[j] < 123) || (x[j] > 64 && x[j] < 91)) // counts every letter from a to z and A to Z
        {
            letters++;
        }
        
        int i = j + 1;
        
        if ((x[j] != 32 && x[i] == 32) || (x[j] != 39 && x[i] == 39)) 
        {
            // if the char isn't a space or ' and the next is a space it add 1 to words
            
            words++;
            verifier++; // counts + 1 in verifier to garantee there're any real word
        }
    }
    
    if (words == 1 && verifier == 0) // if words is 1 it doesn't change the variable words so we took of the value of it
    {
        words--;
        return 1;
    }
    
    float F = 0.0588 * ((letters / words) * 100);
    float S = 0.296 * ((sentences / words) * 100);
    
    float ind = F - S - 15.8;
    return ind;
}


int round_up(float y)
{   
    float number = y - ((int) y);
    
    if (number >= 0.3800)
    {
        number = ((int) y) + 1;
        return number;
    }
    
    return (int) y;
}