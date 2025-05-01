#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main(void)
{
    string word = get_string("Enter word: ");
    int length = strlen(word);
    for(int i = 0; i < length-1; i++)
    {
        if(word[i] > word[i+1])
        {
            printf("no alphabetical order\n");
            return 0;
        }
    }
    printf("yes alphabetical order\n");
}
// return 0 exists the function while break exits only the loop
