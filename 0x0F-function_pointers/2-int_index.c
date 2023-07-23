#include "function_pointers.h"

/**
 * int_index - searches for integer
 * @array: the int array
 * @size: the array size
 * @cmp: the compare function
 * Return: the integer index
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array && size && cmp)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]))
			{
				return (i);
			}
		}
		return (-1);
	}
	return (-1);
}

