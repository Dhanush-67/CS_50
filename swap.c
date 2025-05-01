#include <cs50.h>
#include <stdio.h>

void swap(int x, int y);

int main(void)
{
    int a = 10;
    int b = 50;

    printf("a is %i, b is %i\n", a, b);
    swap(a, b);
    printf("a is %i, b is %i\n", a, b);
}

void swap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
    return;
}
