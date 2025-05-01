#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string uppercase(string x);
int point(string y);

int letters[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    string player1 = get_string("Player 1: ");
    player1 = uppercase(player1);
    int points1 = point(player1);
    string player2 = get_string("Player 2: ");
    player2 = uppercase(player2);
    int points2 = point(player2);
    if (points1 > points2)
    {
        printf("Player 1 wins!\n");
    }
    else if (points1 < points2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

string uppercase(string x)
{
    for (int i = 0, len = strlen(x); i < len; i++)
    {
        x[i] = toupper(x[i]);
    }
    return x;
}

int point(string y)
{
    int totalpoints = 0;
    for (int i = 0, len = strlen(y); i < len; i++)
    {
        if (y[i] >= 65 && y[i] <= 90)
        {
            totalpoints += letters[y[i] - 65];
        }
        else
        {
            totalpoints += 0;
        }
    }
    return totalpoints;
}
