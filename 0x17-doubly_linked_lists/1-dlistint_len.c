#include "lists.h"

/**
 * dlistint_len - a function that returns the number of elements
 * in linked dlistint_t list.
 * @h: a pointer to the first node in the list.
 * Return: the number of element.
 */
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *ptr = h;
	size_t count = 0;

	while (ptr != NULL)
	{
		count += 1;
		ptr = ptr->next;
	}
	return (count);
}

