#include "helpers.h"
#include <math.h>

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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen +
                                 0.189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen +
                                   0.168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen +
                                  0.131 * image[i][j].rgbtBlue);

            if (sepiaBlue > 255)
                sepiaBlue = 255;
            if (sepiaGreen > 255)
                sepiaGreen = 255;
            if (sepiaRed > 255)
                sepiaRed = 255;

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
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
