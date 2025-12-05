#include <stdio.h>
#include <strings.h>

int str_cmp_subsets(const char *s, size_t o1, size_t o2, size_t l)
{
	size_t i;

	for (i = 0; i < l; i++)
	{
		if (s[o1 + i] != s[o2 + i])
		{
			return 0;
		}
	}

	return 1;
}

int str_repeats_start(const char *s, size_t l1, size_t l2)
{
	size_t i;

	if (l1 % l2 != 0)
	{
		return 0;
	}

	for (i = 1; i < l1 / l2; i++)
	{
		if (!str_cmp_subsets(s, 0, i * l2, l2))
		{
			return 0;
		}
	}

	return 1;
}

int is_valid(long int n)
{
	char s[128];
	size_t l1;
	size_t l2;

	sprintf(s, "%li", n);
	l1 = strlen(s);

	for (l2 = 1; l2 <= l1 / 2; l2++)
	{
		if (str_repeats_start(s, l1, l2))
		{
			return 0;
		}
	}

	return 1;
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