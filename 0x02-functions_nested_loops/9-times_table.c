#include "main.h"
/**
 * times_table - prints the 9 times table, starting with 0.
 *
 * Return: Nothing
 */
void times_table(void)
{
	int i, j, s, n;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			s = i * j;
			n = (j + 1) * i;
			if (s < 10)
			{
				_putchar(s + '0');
				if (j < 9)
				{
					_putchar(',');
					_putchar(' ');
					if (n < 10)
					{
						_putchar(' ');
					}
				}
				else
				{
					_putchar('\n');
				}
			}
			else
			{
				_putchar(s / 10 + '0');
				_putchar(s % 10 + '0');
				if (j < 9)
				{
					_putchar(',');
					_putchar(' ');
				}
				else
				{
					_putchar('\n');
				}
			}
		}
	}
}

