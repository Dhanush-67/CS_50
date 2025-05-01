#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string cypher(string p, string k);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Only 2 argumnets\n");
        return 1;
    }

    string x = argv[1];

    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        x[i] = toupper(x[i]);
        if (!isalpha(x[i]) || len != 26 || x[i] == x[i+1])
        {
            printf("Invalid key\n");
            return 1;
        }

        // for(int j = 0; j < )
    }

    // string key = x;
    // string plaintext = get_string("plaintext:  ");
    // string cyphertext = cypher(plaintext, key);
    // printf("ciphertext: %s", cyphertext);
    // printf("\n");
    printf("%s\n", x);
    return 0;
}

string cypher(string p, string k)
{
    for (int i = 0; p[i] != '\0'; i++)
    {
        if (isalpha(p[i]))
        {
            if(isupper(p[i]))
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
