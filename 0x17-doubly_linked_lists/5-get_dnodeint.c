#include "lists.h"

/**
 * get_dnodeint_at_index - a function that returns the nth node
 * of a dlistint_t linked list.
 * @head: a pointer to the first node of the list.
 * @index: the index of the node we are searching.
 * Return: the nth node of a linked list.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *ptr = head;
	unsigned int idx = 0;

	if (ptr == NULL)
	{
		return (NULL);
	}
	while (ptr != NULL)
	{
		if (index == idx)
		{
			return (ptr);
		}
		ptr = ptr->next;
		idx += 1;
	}
	return (NULL);
}

