#include "lists.h"

/**
 * list_len -  a function that calculate the number
 * of elements in a linked list_t list.
 * @h: a pointer to the linked list_t list.
 * Return: the number of elements in a linked list_t list.
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	if (h == NULL)
	{
		return (0);
	}
	else
	{
		while (h != NULL)
		{
			count++;
			h = h->next;
		}
	}
	return (count);
}
