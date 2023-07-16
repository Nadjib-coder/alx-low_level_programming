#include <stdlib.h>
#include "main.h"

/**
 * *string_nconcat - concatenates n bytes of a string to another string
 * @s1: string to append to
 * @s2: string to concatenate from
 * @n: number of bytes from s2 to concatenate to s1
 *
 * Return: pointer to the resulting string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *s;
	unsigned int i, j = 0, len1 = 0, len2 = 0;

	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	if (n < len2)
		s = (char *)malloc(sizeof(char) * (len1 + n + 1));
	else
		s = (char *)malloc(sizeof(char) * (len1 + len2 + 1));

	if (s == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
	{
		s[i] = s1[i];
	}
	if (n < len2)
	{
		while (i < (len1 + n))
		{
			s[i++] = s2[j++];
		}
	}
	else
	{
		while (i < (len1 + len2))
		{
			s[i++] = s2[j++];
		}
	}
	s[i] = '\0';
	return (s);
}

