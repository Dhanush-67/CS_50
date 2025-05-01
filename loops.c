#include <stdio.h>
#include <cs50.h>

void meow(int n);

int main (void)
{
    int x = get_int("COUNT: ");
    meow(x);
}

void meow(int n)
{
    for(int i=0; i<n; i++)
    {
        printf("meow\n");
    }

}
