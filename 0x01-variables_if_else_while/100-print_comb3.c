#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 *
 * prints all possible different combinations of two digits.
 * Return: 0 Always
 */
int main(void)
{
	int i = 0;
	int j = 1;
	int m = 1;

	while (m < 9)
	{
		while (i < 9)
		{
			j = m;
			while (j < 10)
			{
				putchar(48 + i);
				putchar(48 + j);
				if (i < 8)
				{
					putchar(',');
					putchar(' ');
				}
				j++;
			}
			i++;
			m++;
		}
	}


	putchar('\n');
return (0);
}
