#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 *
 * prints all possible different combinations of three digits.
 * Return: 0 Always
 */
int main(void)
{
	int i = 0;
	int j = 1;
	int k = 2;

	while (i < 8)
	{
		while (j < 9)
		{
			while (k < 10)
			{
				putchar(48 + i);
				putchar(48 + j);
				putchar(48 + k);
				if (i < 7)
				{
				putchar(',');
				putchar(' ');
				}
				k++;
			}
		j++;
		k = j + 1;
		}
		j = i + 1;
		i++;
	}
	putchar('\n');
return (0);
}
