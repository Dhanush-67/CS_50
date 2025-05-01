#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int num[] = {3,9,7,4,6,0,1,2,8,3,4};
    int length = sizeof(num) / sizeof(num[0]);

    int swap_count = -1;

    while(!(swap_count == 0))
    {
        swap_count = 0;
        for(int i = 0; i < length-1; i++)
        {
            int swap_num = 0;
            if(num[i] < num[i+1])
            {
                swap_num = num[i];
                num[i] = num[i+1];
                num[i+1] = swap_num;
                swap_count++;
            }
        }
    }
    for(int i = 0; i < length; i++)
    {
        printf("%d\n", num[i]);
    }
}
