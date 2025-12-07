#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f = fopen("input.txt", "r");

    char line[128];
    size_t l;
    int stage = 0;
    long long int i1;
    long long int i2;
    long long int ranges[256][2] = {0};
    size_t ranges_len = 0;
    int is_fresh;
    int fresh_count = 0;

    while (fgets(line, sizeof(line), f) != NULL)
    {
        l = strlen(line);

        if (line[l - 1] == '\n')
        {
            l--;
        }

        if (l == 0)
        {
            stage++;
            continue;
        }

        if (stage == 0)
        {
            sscanf(line, "%lli-%lli", &i1, &i2);

            ranges[ranges_len][0] = i1;
            ranges[ranges_len][1] = i2;

            ranges_len++;
        }
        else
        {
            sscanf(line, "%lli", &i1);

            is_fresh = 0;

            for (i2 = 0; i2 < ranges_len; i2++)
            {
                if (i1 >= ranges[i2][0] && i1 <= ranges[i2][1])
                {
                    is_fresh = 1;
                    break;
                }
            }

            if (is_fresh)
            {
                fresh_count++;
            }
        }
    }

    fclose(f);

    printf("count: %d\n", fresh_count);

    return 0;
}