#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("input.txt", "r");
    char line[128];
    size_t l;
    size_t i1;
    size_t i2;
    int n;
    int max;
    int sum = 0;

    while (fgets(line, sizeof(line), f) != NULL)
    {
        max = 0;

        l = strlen(line);

        if (line[l - 1] == '\n')
        {
            l--;
        }

        for (i1 = 1; i1 < l; i1++)
        {
            for (i2 = 0; i2 < i1; i2++)
            {
                n = (line[i2] - '0') * 10 + (line[i1] - '0');

                if (n > max)
                {
                    max = n;
                }
            }
        }

        sum += max;
    }

    fclose(f);

    printf("sum=%d\n", sum);

    return 0;
}