#include "search_algos.h"
#include <math.h>

/**
 * jump_search -  a function that searches for a value
 * in a sorted array of integers using the Jump search algorithm.
 * @array: a pointer to the first element of the array to search in.
 * @size: the number of elements in array.
 * @value: the value to search for
 * Return: The index of the value we search for.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t n = sqrt(size);
	size_t low = 0, hight = 0, i;

	if (array == NULL)
		return (-1);

	while (hight < size && array[hight] < value)
	{
		printf("Value checked array[%ld] = [%d]", hight, array[hight]);
		low = hight;
		hight += n;
	}

	printf("Value found between indexes [%ld] and [%ld]", low, hight);

	hight = hight < size ? hight : size;

	for (i = low; i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]", i, array[i]);
		if (array[i] == value)
		{
			return (i);
		}
	}
	return (-1);
}
