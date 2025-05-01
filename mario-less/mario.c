#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Enter height: ");
    }
    while (height <= 0);

    for (int x = 0; x < height; x++)
    {
        for (int y = 1; y < height - x; y++)
        {
            printf(" ");
        }
        for (int z = 0; z < x + 1; z++)
        {
            printf("#");
        }
        printf("\n");
    }
}
