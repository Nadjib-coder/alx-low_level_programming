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
	int counter = 0;

	for (i = 0; *(s + i) < '\0'; i++)
	{
		counter++;
	}
	return (counter);
}

