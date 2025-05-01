#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string hello = get_string("Enter: ");
    for(int i = 0; i < 5; i++)
    {
       hello[i] = toupper(hello[i]);
    }
    printf("%s\n", hello);
}
