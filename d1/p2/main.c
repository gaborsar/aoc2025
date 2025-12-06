#include <stdio.h>
#include <stdlib.h>

#define L 0
#define R 1
#define N 100

int read_rotation(FILE *f, int *dir, int *dist)
{
    char line[128];

    if (!fgets(line, sizeof(line), f))
    {
        return 0;
    }

    *dir = line[0] == 'L' ? L : R;
    *dist = atoi(line + 1);

    return 1;
}

void rotate(int *v, int *c, int dir, int dist)
{
    if (dir == L)
    {
        *v = (N - *v) % N;
    }

    *v += dist;
    *c += *v / N;
    *v %= N;

    if (dir == L)
    {
        *v = (N - *v) % N;
    }
}

int main()
{
    FILE *f = fopen("input.txt", "r");
    int dir;
    int dist;
    int v = 50;
    int c = 0;

    while (read_rotation(f, &dir, &dist))
    {
        rotate(&v, &c, dir, dist);
    }

    fclose(f);

    printf("the code is %d\n", c);

    return 0;
}
