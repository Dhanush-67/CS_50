#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average =
                round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j < width / 2)
            {
                RGBTRIPLE temp;
                temp = image[i][j];
                image[i][j] = image[i][width - 1 - j];
                image[i][width - 1 - j] = temp;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = 0;
            float redcount = 0;
            int blue = 0;
            float bluecount = 0;
            int green = 0;
            float greencount = 0;
            for (int k = -1; k < 2; k++)
            {
                if ((i + k) >= 0 && (i + k) <= height - 1)
                {
                    for (int l = -1; l < 2; l++)
                    {
                        if ((j + l) >= 0 && (j + l) <= width - 1)
                        {
                            red += image[i + k][j + l].rgbtRed;
                            redcount++;
                            blue += image[i + k][j + l].rgbtBlue;
                            bluecount++;
                            green += image[i + k][j + l].rgbtGreen;
                            greencount++;
                        }
                    }
                }
            }
            temp[i][j].rgbtBlue = round(blue / bluecount);
            temp[i][j].rgbtGreen = round(green / greencount);
            temp[i][j].rgbtRed = round(red / redcount);
        }
    }
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            image[x][y] = temp[x][y];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int arr1[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int arr2[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redx = 0;
            int bluex = 0;
            int greenx = 0;
            int redy = 0;
            int bluey = 0;
            int greeny = 0;
            int count = 0;

            for (int k = -1; k < 2; k++)
            {
                if ((i + k) >= 0 && (i + k) <= height - 1)
                {
                    for (int l = -1; l < 2; l++)
                    {
                        if ((j + l) >= 0 && (j + l) <= width - 1)
                        {
                            redx += image[i + k][j + l].rgbtRed * arr1[count];
                            bluex += image[i + k][j + l].rgbtBlue * arr1[count];
                            greenx += image[i + k][j + l].rgbtGreen * arr1[count];

                            redy += image[i + k][j + l].rgbtRed * arr2[count];
                            bluey += image[i + k][j + l].rgbtBlue * arr2[count];
                            greeny += image[i + k][j + l].rgbtGreen * arr2[count];

                            count++;
                        }
                        else
                        {
                            count++;
                        }
                    }
                }
                else
                {
                    count += 3;
                }
            }

            int b = round(sqrt((pow(bluex, 2) + pow(bluey, 2))));
            if (b > 255)
                b = 255;
            temp[i][j].rgbtBlue = b;

            int g = round(sqrt((pow(greenx, 2) + pow(greeny, 2))));
            if (g > 255)
                g = 255;
            temp[i][j].rgbtGreen = g;

            int r = round(sqrt((pow(redx, 2) + pow(redy, 2))));
            if (r > 255)
                r = 255;
            temp[i][j].rgbtRed = r;
        }
    }
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            image[x][y] = temp[x][y];
        }
    }
    return;
}
