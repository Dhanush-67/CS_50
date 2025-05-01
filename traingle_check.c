#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>

void check(int x, int y, int z);
int main(void)
{
    int sides[3];

    for(int i = 0; i<=2; i++)
    {
        sides[i] = get_int("Enter: ");
    }

    check(sides[0], sides[1], sides[2]);

}

void check(int x, int y, int z)
{
    if(x > 0 && y>0 && z>0)
    {
        if(x+y>z || x+z>y || z+y> x)
        {
            printf("valid\n");
        }
        else
    {
        printf("invaid\n");
    }
    }
    else
    {
        printf("invaid\n");
    }
}
