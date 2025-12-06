#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#define N 12

size_t find_max_index(const char *line, size_t o1, size_t o2)
{
    size_t max = o1;
    size_t i;

    for (i = o1; i <= o2; i++)
    {
        if (line[i] > line[max])
        {
            max = i;
        }
    }

    return max;
}

long int find_largest_joltage(const char *line)
{
    int indices[N] = {};
    char digits[N + 1] = {};
    size_t l = strlen(line);
    size_t i;

    if (line[l - 1] == '\n')
    {
        l--;
    }

    for (i = 0; i < N; i++)
    {
        indices[i] = find_max_index(
            line,
            i == 0 ? 0 : indices[i - 1] + 1,
            l - N + i);
        digits[i] = line[indices[i]];
    }

    digits[N] = '\0';

    return strtol(digits, NULL, 10);
}

int main()
{
    FILE *f = NULL;
    char line[128];
    size_t i1;
    size_t i2;
    int n;
    long int sum = 0;

    f = fopen("input.txt", "r");

    while (fgets(line, sizeof(line), f) != NULL)
    {
        sum += find_largest_joltage(line);
    }

    fclose(f);

    printf("sum=%li\n", sum);

    return 0;
}