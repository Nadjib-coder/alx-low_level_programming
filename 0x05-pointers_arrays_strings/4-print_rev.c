#include "main.h"
#include <stdio.h>

/**
 * print_rev - a function that prints a string, in reverse,
 * followed by a new line.
 * @s: the string.
 * Return: Nothing.
 */
void print_rev(char *s)
{
	int i;

	for (i = _strlen(s); i >= 0; i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}

