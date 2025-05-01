#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>

void check(long card);
long some_num1 = 0;
long some_num2 = 0;
bool american = false;
bool master = false;
bool visa = false;

int main(void)
{
    long number = get_long("Number: ");
    check(number);
}

void check(long card)
{
    int i = 1;

    while (card > 0)
    {
        if (i % 2 == 0)
        {
            long x = card % 10 * 2;

            if (x >= 10)
            {
                x = x % 10 + x / 10;
            }
            some_num1 += x;
        }

        else
        {
            some_num2 += card % 10;
        }

        card /= 10;
        if (i == 13)
        {
            if (card == 34 || card == 37)
            {
                american = true;
            }
        }

        if (i == 14)
        {
            if (card == 51 || card == 52 || card == 53 || card == 54 || card == 55)
            {
                master = true;
            }
        }
        if (i == 12)
        {
            if (card == 4)
            {
                visa = true;
            }
        }
        if (i == 15)
        {
            if (card == 4)
            {
                visa = true;
            }
        }
        i++;
    }

    if ((some_num1 + some_num2) % 10 == 0)
    {
        if (american)
        {
            printf("AMEX\n");
        }
        else if (master)
        {
            printf("MASTERCARD\n");
        }
        else if (visa)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
