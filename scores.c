#include <stdio.h>
#include <cs50.h>

float average(int length, int array[]);

int main(void)
{
    int N = get_int("Enter length: ");
    int scores[N];
    for(int i = 0; i<=N; i++)
    {
        scores[i] = get_int("Enter number: ");
    }
    printf("Average: %f\n",average(N, scores));
}

float average(int length, int array[])
{
    int sum = 0;
    for(int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum/ (float) length;
}
