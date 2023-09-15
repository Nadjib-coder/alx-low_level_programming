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
	dlistint_t *current = (*h), *new_node;
	unsigned int i = 0;

	if (idx == 0)
	{
		return (add_dnodeint(h, n));
	}
	while (current != NULL && i < idx - 1)
	{
		current = current->next;
		i++;
	}
	if (current == NULL && i < idx - 1)
		return (NULL);
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	if (current != NULL)
	{
		new_node->next = current->next;
		new_node->prev = current;
		if (current->next != NULL)
			current->next->prev = new_node;
		current->next = new_node;
	}
	else
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		if (*h != NULL)
		{
			while ((*h)->prev != NULL)
				*h = (*h)->prev;
			(*h)->prev = new_node;
		}
		*h = new_node;
	}
	return (new_node);
}

