#include "main.h"

/**
 * flip_bits - a function that count the number of bits you
 * would need to flip to get from one number to another.
 * @n: first number.
 * @m: second number.
 * Return: the number of bits.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int current;
	unsigned long int exclusiv = n ^ m;
	int count = 0, i;

	for (i = 63; i >= 0; i--)
	{
		current = exclusiv >> i;
		if (current & 1)
		{
			count++;
		}
	}
	return (count);
}

