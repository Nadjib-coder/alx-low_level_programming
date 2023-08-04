#include "main.h"

/**
 * binary_to_uint - a function that converts a binary
 * number to an unsigned int.
 * @b: a pointer to a string of 0 and 1 chars/
 * Return: the converted number, or NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result;

	if (b == NULL)
	{
		return (NULL);
	}
	while (*b != '\0')
	{
		if (*b != '0' && *b != '1')
		{
			return (NULL);
		}
		result << 1;
		result += (*b - '0');
		b++;
	}
	return (result);
}

