#include "main.h"
#include <stdio.h>

/**
 * puts2 - a function that prints every other character of a string,
 * starting with the first character, followed by a new line.
 * @str: the string.
 * Return: Nothing.
 */
void puts2(char *str)
{
	int i;
	int length = 0;

	for (i = 0; i < length - 1; i++)
	{
		if (str[i] % 2 == 0)
		{
			_putchar(str[i])
		}
	}
	_putchar('\n');
}

