#include <stdio.h>
#include <strings.h>

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
	FILE *f = NULL;
	long int n1;
	long int n2;
	long long int sum = 0;

	f = fopen("input.txt", "r");

	while (1)
	{
		fscanf(f, "%li-%li", &n1, &n2);
		sum += process_range(n1, n2);

		if (fgetc(f) == EOF)
		{
			break;
		}
	}

	fclose(f);

	printf("sum=%lli\n", sum);

	return 0;
}