#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

void mergesort(int arr[], int length);
void merge(int arr[], int left[], int left_length, int right[], int right_length);

int main(void)
{
    char *numbers = get_string("Enter: ");
    int len = strlen(numbers);
    int num_array[len];

    for(int i = 0; i < len; i++)
    {
        num_array[i] = numbers[i] - '0';
    }

    mergesort(num_array, len);

    // Print sorted array
    printf("Sorted array:\n");
    for(int i = 0; i < len; i++)
    {
        printf("%d ", num_array[i]);
    }
    printf("\n");

    return 0;
}

void mergesort(int arr[], int length)
{
    if(length < 2)
    {
        return;
    }

    int mid = length / 2;
    int left[mid];
    int right[length - mid];

    for(int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }
    for(int i = mid; i < length; i++)
    {
        right[i - mid] = arr[i];
    }

    mergesort(left, mid);
    mergesort(right, length - mid);
    merge(arr, left, mid, right, length - mid);
}

void merge(int arr[], int left[], int left_length, int right[], int right_length)
{
    int i = 0, j = 0, k = 0;

    while(i < left_length && j < right_length)
    {
        if(left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }

    while(i < left_length)
    {
        arr[k++] = left[i++];
    }

    while(j < right_length)
    {
        arr[k++] = right[j++];
    }
}
