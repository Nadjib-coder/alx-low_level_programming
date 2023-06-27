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
	int length;

	length = _strlen(s);
	for (i = length; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}

