#include "search_algos.h"

/**
 * linear_search - This is a function that searches for
 * a value in an array of integers using the Linear search algorithm
 * @array: the array that we search in
 * @size: the size of the array
 * @value: the value that we search for
 * Return: the index of the value or -1 if not foun
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
	{
		return (-1);
	}
	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
		{
			return (i);
		}
	}
	return (-1);
}
