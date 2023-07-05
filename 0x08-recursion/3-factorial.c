#include "main.h"

/**
 * factorial - a function that returns the factorial of
 * a given number.
 * @n: the input number
 * Return: the factorial.
 */
int factorial(int n)
{
	if (n == 0 || n == 1)
	{
		return (1);
	}
	else
	{
		return (n * factorial(n - 1));
	}
}

