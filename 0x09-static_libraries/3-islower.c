#include "main.h"

/**
 * _islower - function that checks for lowercase character
 * @c: the character
 * Return: 1 id c lowercase
 * or 0 otherwise
 */
int _islower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
		return (0);
}

