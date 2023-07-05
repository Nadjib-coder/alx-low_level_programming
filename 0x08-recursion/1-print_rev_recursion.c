#include "main.h"

/**
 * _print_rev_recursion - a function that prints a string in reverse.
 * @s: the addres of the first character in th string
 * Return: Nothing.
 */
void _print_rev_recursion(char *s)
{
	if (*s == '\0')
	{
		return;
	}
	else
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
}

