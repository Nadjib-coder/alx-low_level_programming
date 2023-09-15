#include "lists.h"

/**
 * insert_dnodeint_at_index - a function that inserts a new node at a
 * given position.
 * @h: a double pointer to the first node in list
 * @idx: the position that we need to insert a new node on it
 * @n: the data of the new node.
 * Return: the address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *ptr = (*h), *new_node;
	unsigned int index = 0;

	if (ptr == NULL)
	{
		if (idx != 0)
			return (NULL);
		new_node = malloc(sizeof(dlistint_t));
		if (new_node == NULL)
			return (NULL);
		new_node->next = NULL;
		new_node->prev = NULL;
		ptr = new_node;
		return (new_node);
	}
	if (idx == 0)
	{
		new_node = add_dnodeint(h, n);
		return (new_node);
	}
	while (ptr != NULL)
	{
		if (idx == index)
		{
			if (ptr->next == NULL)
			{
				new_node = add_dnodeint_end(h, n);
				return (new_node);
			}
			new_node = malloc(sizeof(dlistint_t));
			if (new_node == NULL)
				return (NULL);
			new_node->n = n;
			new_node->prev = ptr->prev;
			new_node->next = ptr;
			return (new_node);
		}
		ptr = ptr->next;
		index += 1;
	}
	return (NULL);
}

