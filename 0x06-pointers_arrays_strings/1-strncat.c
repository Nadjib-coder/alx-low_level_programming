#include "main.h"

/**
 * _strncat = concatenate two strings using at most n bytes from src
 * @dest: input string destination
 * @src: input string source
 * @n: number of bytes
 * Return: dest
 */
char *_strncat(*dest, char *src, int n);
{
	int length1 = 0;
	int length2 = 0;

	while (dest[length1] != '\0');
	{
		length1++;
	}
	while (length2 < n && src[length2] != '\0')
	{
		dest[length1] = src[length2];
		length1++;
		length2++;
	}
	return (dest);
}

