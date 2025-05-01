#include <cs50.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Only filename\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Could not open %s\n", argv[1]);
        return 1;
    }

    uint8_t buffer[512];
    int count = 0;
    char filename[8];
    bool jpeg_found = false;
    FILE *img;
    while (fread(buffer, sizeof(buffer), 1, f) != 0)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (!jpeg_found)
            {
                jpeg_found = true;
                sprintf(filename, "%03i.jpg", count);
                count++;
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(buffer), 1, img);
            }
            else
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", count);
                count++;
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(buffer), 1, img);
            }
        }
        else if (jpeg_found)
        {
            fwrite(buffer, sizeof(buffer), 1, img);
        }
    }
    fclose(img);
    fclose(f);
}
