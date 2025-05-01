#include <cs50.h>
#include <stdio.h>

void rightwall(int x, int height);
void leftwall(int x, int height);

int main(void)
{
    int height;
    do
    {
        height = get_int("Enter height: ");
    }
    while (height < 1 || height > 8);

    int x;
    for (x = 0; x < height; x++)
    {
        rightwall(x, height);
        printf(" ");
        printf(" ");
        leftwall(x, height);
        printf("\n");
    }
}

void leftwall(int x, int height)
{
    for (int i = 0; i < x + 1; i++)
    {
        printf("#");
    }
}

void rightwall(int x, int height)
{
    for (int i = 1; i < height - x; i++)
    {
        printf(" ");
    }
    for (int j = 0; j < x + 1; j++)
    {
        printf("#");
    }
}
