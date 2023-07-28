#include "lists.h"
#include <stdio.h>

/**
 * print_list - a function that prints all the elements of a list_t list.
 * @h:a pointer to the list list_t
 * Return: the number of nodes printed.
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		const list_t *ptr = h;

		if (ptr->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%u] %s\n", ptr->len, ptr->str);
		}
		ptr = ptr->next;
		count++;
	}
	return (count);
}

