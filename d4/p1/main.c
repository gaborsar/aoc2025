#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f = fopen("input.txt", "r");

    char line[256];
    char data[256][256] = {0};
    size_t w = 0;
    size_t h = 0;
    size_t x1;
    size_t y1;
    size_t x2_min;
    size_t x2_max;
    size_t y2_min;
    size_t y2_max;
    size_t x2;
    size_t y2;
    int c1;
    int c2 = 0;

    y1 = 0;
    while (fgets(line, sizeof(line), f) != NULL)
    {
        if (w == 0)
        {
            w = strlen(line);
            if (line[w - 1] == '\n')
            {
                w--;
            }
        }
        for (x1 = 0; x1 < w; x1++)
        {
            data[y1][x1] = line[x1];
        }
        y1++;
    }
    h = y1;

    fclose(f);

    for (y1 = 0; y1 < h; y1++)
    {
        y2_min = y1 == 0 ? y1 : y1 - 1;
        y2_max = y1 == h - 1 ? y1 : y1 + 1;

        for (x1 = 0; x1 < w; x1++)
        {
            if (data[y1][x1] != '@')
            {
                continue;
            }

            x2_min = x1 == 0 ? x1 : x1 - 1;
            x2_max = x1 == w - 1 ? x1 : x1 + 1;
            c1 = 0;

            for (y2 = y2_min; y2 <= y2_max; y2++)
            {
                for (x2 = x2_min; x2 <= x2_max; x2++)
                {
                    if (y2 == y1 && x2 == x1)
                    {
                        continue;
                    }

                    if (data[y2][x2] == '@')
                    {
                        c1++;
                    }
                }
            }

            if (c1 < 4)
            {
                c2++;
            }
        }
    }

    printf("count=%d\n", c2);

    return 0;
}