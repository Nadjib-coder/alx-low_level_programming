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

	while (dest[length1] != '\0')
	{
		length1++;
	}
	while (src[length2] != '\0')
	{
		dest[length1] = src[length2];
		length1++;
		length2++;
	}
	dest[length1] = '\0';
	return (dest);
}

