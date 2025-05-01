#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string cypher(string x, int y);

int main(int argc, string argv[])
{
    if (argc != 2 || atoi(argv[1]) < 0)
    {
        printf("Only two arguments and positive integers\n");
        return 1;
    }

    string x = argv[1];
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (isalpha(x[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext:  ");
    string cyphertext = cypher(plaintext, key);
    printf("ciphertext: %s", cyphertext);
    printf("\n");
    return 0;
}

string cypher(string x, int y)
{
    for (int i = 0; x[i] != '\0'; i++)
    {
        int z = y;
        if (isalpha(x[i]))
        {
            if (isupper(x[i]))
            {
                while (z != 0)
                {
                    x[i] += 1;
                    if (x[i] > 90)
                    {
                        x[i] = 65;
                    }
                    z--;
                }
            }
            else
            {
                while (z != 0)
                {
                    x[i] += 1;
                    if (x[i] > 122)
                    {
                        x[i] = 97;
                    }
                    z--;
                }
            }
        }
    }
    return x;
}
