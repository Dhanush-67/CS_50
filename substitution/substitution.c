#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string cypher(string p, string k);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Only 2 argumnets\n");
        return 1;
    }

    string x = argv[1];

    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        x[i] = toupper(x[i]);
        if (!isalpha(x[i]) || len != 26)
        {
            printf("Invalid key\n");
            return 1;
        }
        for (int j = 0; j < len; j++)
        {
            if ((x[i] == x[j] || x[i] == x[j] + 32) && i != j)
            {
                printf("Invalid key\n");
                return 1;
            }
        }
    }

    string key = x;
    string plaintext = get_string("plaintext:  ");
    string cyphertext = cypher(plaintext, key);
    printf("ciphertext: %s", cyphertext);
    printf("\n");
    return 0;
}

string cypher(string p, string k)
{
    for (int i = 0; p[i] != '\0'; i++)
    {
        if (isalpha(p[i]))
        {
            if (isupper(p[i]))
            {
                p[i] = k[p[i] - 65];
            }
            else
            {
                p[i] = toupper(p[i]);
                p[i] = k[p[i] - 65];
                p[i] = tolower(p[i]);
            }
        }
    }
    return p;
}

// strings cannot be modified in main but can be in other functions
// strings and arrays when set to a variable and when that variable is changed even orignal will change unlike actual variables
// inputs can be modified in main as well
