#include <stdio.h>
#include <string.h>

#define START -1
#define SPLIT -2

int main()
{
    FILE *f = fopen("input.txt", "r");

    long int data[256][256] = {0};

    char line[256] = {0};
    size_t l = 0;
    char c;

    size_t w = 0;
    size_t h = 0;

    size_t x = 0;
    size_t y = 0;

    long long int timelines = 0;

    while (fgets(line, sizeof(line), f) != NULL)
    {
        l = strlen(line);

        if (line[l - 1] == '\n')
        {
            l--;
        }

        if (l > w)
        {
            w = l;
        }

        for (x = 0; x < l; x++)
        {
            c = line[x];

            if (c == 'S')
            {
                data[y][x] = START;
            }
            else if (c == '^')
            {
                data[y][x] = SPLIT;
            }
        }

        y++;
    }

    h = y;

    fclose(f);

    for (y = 1; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            if (data[y - 1][x] == START)
            {
                data[y][x] = 1;
            }
            else if (data[y][x] == SPLIT)
            {
                if (x > 0)
                {
                    data[y][x - 1] += data[y - 1][x];
                }
                if (x < w - 1)
                {
                    data[y][x + 1] += data[y - 1][x];
                }
            }
            else if (data[y - 1][x] != SPLIT)
            {
                data[y][x] += data[y - 1][x];
            }
        }
    }

    for (x = 0; x < w; x++)
    {
        timelines += data[h - 1][x];
    }

    printf("timelines=%lli\n", timelines);

    return 0;
}