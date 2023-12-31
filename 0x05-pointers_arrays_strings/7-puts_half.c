#include "main.h"
#include <stdio.h>

/**
 * puts_half - a function that prints half of a string, followed by a new line.
 * @str: the string.
 * Return: Nothing.
 */
void puts_half(char *str)
{
	int i;
	int n;
	int length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	if (length % 2 == 0)
	{
		n = length / 2;
		for (i = n; i < length; i++)
		{
			_putchar(str[i]);
		}
		_putchar('\n');
	}
	else
	{
		n = (length - 1) / 2;
		for (i = n + 1; i < length; i++)
		{
			_putchar(str[i]);
		}
		_putchar('\n');
	}
}

