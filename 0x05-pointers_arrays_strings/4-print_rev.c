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
	int length = 0;

        while (s[length] != '\0')
        {
                length++;
        }
	for (i = length - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}

