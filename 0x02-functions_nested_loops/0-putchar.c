#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - A program that prints _putchar
 * Return: 0 (Success)
 */
int main(void)
{
	char c[] = "_putchar";
	int i;

	for (i = 0; i != '\0'; i++)
	{
		_putchar(c[i]);
	}
	_putchar('\n');
	return (0);
}
/**
 * _putchar - a function writes the character c to stdout
 * @c: the character to print
 *
 * Return: on success 1.
 * on error, -1 is returned, and errno is set appropriately/
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
