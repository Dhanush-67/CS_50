#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

string uppercase(string x);
int countletter(string a);
int countword(string b);
int countsentence(string c);

int main(void)
{
    string phrase = get_string("Text: ");
    phrase = uppercase(phrase);
    int w = countword(phrase);
    float l = ((float) countletter(phrase) / w) * 100;
    float s = ((float) countsentence(phrase) / w) * 100;
    int index = round((0.0588 * l - 0.296 * s - 15.8));
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

string uppercase(string x)
{
    for (int i = 0, len = strlen(x); i < len; i++)
    {
        x[i] = toupper(x[i]);
    }
    return x;
}

int countletter(string a)
{
    int count = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] >= 65 && a[i] <= 90)
            count++;
    }
    return count;
}

int countword(string b)
{
    int count = 1;
    for (int i = 0; b[i] != '\0'; i++)
    {
        if (b[i] == 32)
        {
            count++;
        }
    }
    return count;
}

int countsentence(string c)
{
    int count = 0;
    for (int i = 0; c[i] != '\0'; i++)
    {
        if (c[i] == 33 || c[i] == 46 || c[i] == 63)
        {
            count++;
        }
    }
    return count;
}
