#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = get_int("Enter Height: ");

    for(int x = 0; x < height; x++)
    {
        for(int y = 0; y < x+1; y++)
        {
            printf("#");
        }
        printf("\n");
    }
}
