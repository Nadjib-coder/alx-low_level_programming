#include "main.h"

/**
 * main - A program that write _putchar to stdout
 * Return: 0 Always
 */
int main(void)
{
	char c[] = "_putchar";
	int i;

	for (i = 0; c[i] != '\0'; i++)
	{
		_putchar(c[i]);
	}
	_putchar('\n');
	return (0);
}

