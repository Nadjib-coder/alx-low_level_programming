#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 *
 * prints all possible combinations of two two-digit numbers.
 * Return: 0 Always
 */
int main(void)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int m = 1;

	while (i < 10)
	{
		while (j < 10)
		{
			while (k < 10)
			{
				while (m < 10)
				{
					putchar(i + 48);
					putchar(j + 48);
					putchar(' ');
					putchar(k + 48);
					putchar(m + 48);
					if (!(i == 9 && j == 8 && k == 9 && m == 9))
					{
						putchar(',');
						putchar(' ');
					}
					m++;
				}
				m = 0;
				k++;
			}
			m = j + 2;
			k = i;
			j++;
		}
		j = 0;
		m = j + 1;
		i++;
		k = i;
	}
	putchar('\n');
return (0);
}
