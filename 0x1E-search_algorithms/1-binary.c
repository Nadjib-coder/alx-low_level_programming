#include "search_algos.h"

/**
 * binary_search - This is a function that searches for a value
 * in a sorted array of integers using the Binary search algorithm.
 * @array: an array where we search
 * @size: the size of the array
 * @value: the value that we search for
 * Return: the index of the value or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
	size_t left = 0, right = size - 1, mid, i;

	if (array == NULL)
		return (-1);

	while (left <= right)
	{
		mid = (left + right) / 2;
		/* Print the current search range */
		printf("Searching in array:");
		for (i = left; i <= right; i++)
		{
			if (i < right)
			{
				printf(" %d,", array[i]);
			}
			else
			{
				printf(" %d\n", array[i]);
			}
		}
		if (array[mid] == value)
		{
			return (mid); /* Value found */
		}
		else if (array[mid] > value)
		{
			right = mid - 1; /* Search in the right half */
		}
		else
		{
			left = mid + 1; /* Search in the left half */
		}
	}
	return (-1);
}
