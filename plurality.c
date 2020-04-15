#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner();



int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }
    
    

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int j = 0; j <= MAX; j++) // loop a certain quantity of votes and compares it.
    {
        if (strcmp(name, candidates[j].name) == 0) // compares if that name where declared as a candidate and search it
        {
            candidates[j].votes += 1; // add 1 in their's votes
            return true;
        }
        else if (j == candidate_count - 1) // if for reaches the last value there're not this candidate
        {
            return false;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner()
{
    int bigger = 0;
    string names[MAX];
    int times = 0;
    int j = 0;
    
    for (int k = 0; k < MAX; k++)
    {
        if (times != 0 && candidates[k].votes > bigger)
        {
            bigger = candidates[k].votes; // change the biggest number to compare wich one have moe votes
            names[0] = candidates[k].name; // overlap the previus winner
        }
        
        
        else if (bigger == 0 && times == 0)
        {
            bigger = candidates[0].votes;
            names[0] = candidates[0].name; 
            times++; // adds 1 to change where the next winner will be saved at the array
        }
        
        else if (bigger != 0 && candidates[k].votes == bigger)
        {
            names[times] = candidates[k].name; // pick another winner if there's a tie
            times++; // adds one more to change where the next winner if there's another winner 
            
        }
    }
    
    if (times > 1) // times works as a garantee to verify if there're more than 1 winner
    {
        do
        {   
            printf("%s\n", names[j]); // prints 1 winner per line
            j++;
        }
        while (j < times);
    }
    
    else
    {
        printf("%s\n", names[0]); // prints only a winner
    }
    
    return;
}

