#include <stdio.h>
#include <cs50.h>

int length(string s);

int main(void)
{
    string name = get_string("Enter name: ");
    int count = length(name);
    printf("%i\n", count);
}

int length(string s)
{
    int i = 0;
    while(s[i] != '\0')
    {
        i++;
    }
    return i;
}
