#include "main.h"
#include <stdio.h>

/**
 * _strlen - a function that returns the length of a string.
 * @s: string.
 * Return: the length of string.
 */
int _strlen(char *s)
{
	int i;
	char *p;
	int counter = 0;

	p = s;
	for (i = 0; *(p + i) < '\0'; i++)
	{
		counter++;
	}
	return (counter);
}

