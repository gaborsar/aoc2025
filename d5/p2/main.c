#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f = fopen("input.txt", "r");

    char line[128];
    size_t l;
    long long int i1;
    long long int i2;
    long long int t1;
    long long int t2;
    long long int ranges[256][2] = {0};
    size_t ranges_len = 0;
    long long int c = 0;

    while (fgets(line, sizeof(line), f) != NULL)
    {
        l = strlen(line);

        if (line[l - 1] == '\n')
        {
            l--;
        }

        sscanf(line, "%lli-%lli", &i1, &i2);

        ranges[ranges_len][0] = i1;
        ranges[ranges_len][1] = i2;

        ranges_len++;
    }

    fclose(f);

    for (i1 = 1; i1 < ranges_len; i1++)
    {
        for (i2 = 0; i2 < i1; i2++)
        {
            if (ranges[i1][0] < ranges[i2][0] ||
                (ranges[i1][0] == ranges[i2][0] &&
                 ranges[i1][1] < ranges[i2][1]))
            {
                t1 = ranges[i1][0];
                t2 = ranges[i1][1];

                ranges[i1][0] = ranges[i2][0];
                ranges[i1][1] = ranges[i2][1];

                ranges[i2][0] = t1;
                ranges[i2][1] = t2;
            }
        }
    }

    for (i1 = 0; i1 < ranges_len - 1; i1++)
    {
        i2 = i1 + 1;

        if (ranges[i1][1] >= ranges[i2][0])
        {
            if (ranges[i1][1] > ranges[i2][1])
            {
                ranges[i2][1] = ranges[i1][1];
            }

            ranges[i1][1] = ranges[i2][0] - 1;
        }
    }

    for (i1 = 0; i1 < ranges_len; i1++)
    {
        c += ranges[i1][1] - ranges[i1][0] + 1;
    }

    printf("count=%lli\n", c);

    return 0;
}