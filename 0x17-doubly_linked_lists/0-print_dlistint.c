#include "lists.h"

/**
 * print_dlistint - a function that prints all the elements of
 * a dlistint_t list.
 * @h: a pointer to the first node in the list.
 * Return: the number of nodes.
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint *ptr = h;
	size_t  count = 0;

	while (ptr != NULL)
	{
		print("%d\n", ptr->n);
		ptr = ptr->next;
		count += 1;
	}
	return (count);
}

