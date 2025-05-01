#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int num[] = {1,2,3,4,5};

    for(int i = 0; i < 5; i++)
    {
        int highest = 0;
        int index;
        for(int j = 0+i; j < 5; j++)
        {
            //int highest = 0;
            if(num[j] > highest)
            {
                highest = num[j];
                index = j;
            }
        }
        num[index] = num[i];
        num[i] = highest;
        printf("%d ", num[i]);
    }
}
