#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

void mergesort(int arr[], int length);

int main(void)
{
    char *numbers = get_string("Enter: ");
    int len = strlen(numbers);
    int num_array[len];

    for(int i = 0; i < len; i ++)
    {
        num_array[i] = numbers[i] - '0';
    }

    mergesort(num_array,len);
}

void mergesort(int arr[], int length)
{
    

    if(length == 1)
    {
        return arr;
    }
    else
    {
        int mid = length/2;
        int left[mid];
        int right[length-mid];

        for(int i = 0; i < mid; i++)
        {
            left[i] = arr[i];
        }
        mergesort(left,mid);

        for(int i = mid; i < length; i++)
        {
            right[i-mid] = arr[i];
        }
        mergesort(right,length-mid);
    }
}
