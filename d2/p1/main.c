#include <stdio.h>
#include <string.h>

int is_valid(long int n)
{
    char s[128];
    size_t l;
    size_t i;

    sprintf(s, "%li", n);
    l = strlen(s);

    if (l % 2 != 0)
    {
        return 1;
    }

    for (i = 0; i < l / 2; i++)
    {
        if (s[i] != s[l / 2 + i])
        {
            return 1;
        }
    }

    return 0;
}

long long int process_range(long int n1, long int n2)
{
    long int n;
    long long int sum = 0;

    for (n = n1; n <= n2; n++)
    {
        if (!is_valid(n))
        {
            sum += n;
        }
    }

    return sum;
}

int main()
{
    FILE *f = fopen("input.txt", "r");
    long int n1;
    long int n2;
    long long int sum = 0;

    while (fscanf(f, "%li-%li", &n1, &n2) == 2)
    {
        sum += process_range(n1, n2);
        fgetc(f);
    }

    fclose(f);

    printf("sum=%lli\n", sum);

    return 0;
}