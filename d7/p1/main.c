#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f = fopen("input.txt", "r");

    char data[256][256] = {0};

    char line[256] = {0};
    size_t l = 0;

    size_t w = 0;
    size_t h = 0;

    size_t x = 0;
    size_t y = 0;

    int splits = 0;

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
            data[y][x] = line[x];
        }

        y++;
    }

    h = y;

    fclose(f);

    for (y = 1; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            if (data[y - 1][x] == 'S')
            {
                data[y][x] = '|';
            }
            else if (data[y][x] == '^' && data[y - 1][x] == '|')
            {
                if (x > 0)
                {
                    data[y][x - 1] = '|';
                }
                if (x < w - 1)
                {
                    data[y][x + 1] = '|';
                }
                splits++;
            }
            else if (data[y][x] == '.' && data[y - 1][x] == '|')
            {
                data[y][x] = '|';
            }
        }
    }

    printf("splits=%d\n", splits);

    return 0;
}