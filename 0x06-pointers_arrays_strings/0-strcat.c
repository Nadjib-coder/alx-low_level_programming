#include "main.h"

/**
 * _strcat - a function that concatenates two strings
 * @dest: destination string
 * @src: source of the string
 * Return: a pointer to the string dest.
 */
char *_strcat(char *dest, char *src)
{
	int length1 = 0;
	int length2 = 0;
	int i, j;

	while (dest[length1] != '\0')
	{
		length1++;
	}
	while (src[length2] != '\0')
	{
		length2++;
	}
	for (i = length1 + 1, j = 0; i < length1 + length2 && j != '\0'; i++, j++)
	{
		dest[i] = src[j];
	}
	return (dest);
}

