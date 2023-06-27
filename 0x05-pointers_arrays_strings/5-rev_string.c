#include "main.h"
#include <stdio.h>

/**
 * rev_string - a function that reverses a string.
 * @s: the string.
 * Return: Nothing.
 */
void rev_string(char *s)
{
	int i;
	int j;
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}
	for (i = 0, j = length - 1; i < j; i++, j--)
	{
		char temp = s[i];

		s[i] = s[j];
		s[j] = temp;
	}
}

