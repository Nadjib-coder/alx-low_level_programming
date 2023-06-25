#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * prints all possible combinations of single-digit numbers.
 * Return: 0 Always
 */
int main(void)
{
	int i = 0;

	for (i = 0; i < 10; i++)
	{
		putchar(i + '0');
		if (i != 9)
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}

