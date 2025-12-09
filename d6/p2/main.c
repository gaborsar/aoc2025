#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f = fopen("input.txt", "r");

    char input[5][4096] = {0};

    char line[4096] = {0};
    size_t l;

    size_t w = 0;
    size_t h;

    size_t x;
    size_t y = 0;
    size_t i;
    size_t j;

    size_t col_offsets[1024] = {0};
    size_t col_count = 0;

    size_t col_offset;
    size_t col_len;

    char c;
    char op;

    int n;
    long int col_result;
    long long int sum = 0;

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
            input[y][x] = line[x];
        }

        y++;
    }

    h = y;

    fclose(f);

    for (x = 0; x < w; x++)
    {
        c = input[h - 1][x];

        if (c == '+' || c == '*')
        {
            col_offsets[col_count++] = x;
        }
    }

    for (i = 0; i < col_count; i++)
    {
        col_offset = col_offsets[i];

        if (i < col_count - 1)
        {
            col_len = col_offsets[i + 1] - col_offset - 1;
        }
        else
        {
            col_len = w - col_offset;
        }

        op = input[h - 1][col_offset];

        switch (op)
        {
        case '+':
            col_result = 0;
            break;
        case '*':
            col_result = 1;
            break;
        }

        for (j = 0; j < col_len; j++)
        {
            x = col_offset + col_len - j - 1;

            n = 0;

            for (y = 0; y < h; y++)
            {
                c = input[y][x];

                if (c >= '0' && c <= '9')
                {
                    n = n * 10 + (c - '0');
                }
            }

            switch (op)
            {
            case '+':
                col_result += n;
                break;
            case '*':
                col_result *= n;
                break;
            }
        }

        sum += col_result;
    }

    printf("sum=%lli\n", sum);

    return 0;
}