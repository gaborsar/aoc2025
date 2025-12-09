#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f = fopen("input.txt", "r");

    long long int inputs[4][1024] = {0};
    char ops[1024] = {0};

    char line[4096];
    size_t l;

    int r;
    int n;
    int o1;
    int o2;

    long int results[1024] = {0};
    long long int sum = 0;

    size_t w = 0;
    size_t h;

    size_t i1 = 0;
    size_t i2;

    while (fgets(line, sizeof(line), f) != NULL)
    {
        o1 = 0;
        i2 = 0;

        while (1)
        {
            r = sscanf(line + o1, " %i%n", &n, &o2);
            o1 += o2;

            if (r != 1)
            {
                break;
            }

            inputs[i1][i2++] = n;

            if (i2 > w)
            {
                w = i2;
            }
        }

        if (i2 != 0)
        {
            i1++;
            h = i1;
        }
    }

    i1 = 0;
    i2 = 0;
    l = strlen(line);

    for (i1 = 0; i1 < l; i1++)
    {
        switch (line[i1])
        {
        case '+':
            ops[i2] = line[i1];
            results[i2] = 0;
            i2++;
            break;
        case '*':
            ops[i2] = line[i1];
            results[i2] = 1;
            i2++;
            break;
        }
    }

    for (i1 = 0; i1 < w; i1++)
    {
        for (i2 = 0; i2 < h; i2++)
        {
            switch (ops[i1])
            {
            case '+':
                results[i1] += inputs[i2][i1];
                break;
            case '*':
                results[i1] *= inputs[i2][i1];
                break;
            }
        }
    }

    for (i1 = 0; i1 < w; i1++)
    {
        sum += results[i1];
    }

    printf("sum=%lli\n", sum);

    fclose(f);

    return 0;
}