#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * _strdup - duplicate to new memory space location
 * @str: char
 * Return: 0
 */
char *_strdup(char *str)
{
	char *a;
	int len = 0, i;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[len] != '\0')
	{
		len++;
	}
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (a == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len; i++)
	{
		a[i] = str[i];
	}
	return (a);
}

