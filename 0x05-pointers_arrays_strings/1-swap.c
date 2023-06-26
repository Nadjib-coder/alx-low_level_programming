#include <stdio.h>

/**
 * swap_int - a function that swaps the values of two integers.
 * @a: first integer to swaped
 * @b: second integer to swaped
 * Return: Nothing.
 */
void swap_int(int *a, int *b)
{
	int *p1;
	int *p2;

	p1 = a;
	p2 = b;
	*p1 = *b;
	*p2 = *a;
}

