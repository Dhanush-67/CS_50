#include <stdio.h>
#include <cs50.h>

float add(float a, float b);
int main (void)
{
    int x = get_int("X: ");
    int y =  get_int("Y: ");
    printf("%f\n", add((float)x,(float)y));
}

float add(float a, float b)
{
    return a+b;
}
