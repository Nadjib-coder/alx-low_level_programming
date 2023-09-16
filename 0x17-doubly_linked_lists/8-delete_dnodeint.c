#include "lists.h"

/**
 * delete_dnodeint_at_index - a function that deletes the node at
 * index index of a dlistint_t linked list.
 * @head: a double pointer to the first node in the list.
 * @index: the index of the node we want to delete.
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *ptr = (*head);
	unsigned int i = 0;

	if (head == NULL)
		return (-1);
	if (index == 0)
	{
		(*head) = ptr->next;
		(*head)->prev = NULL;
		free(ptr);
		return (1);
	}
	while (ptr != NULL)
	{
		if (index == i)
		{
			if (ptr->next != NULL)
			{
				ptr->next->prev = ptr->prev;
			}
			ptr->prev->next = ptr->next;
			free(ptr);
			return (1);
		}
		ptr = ptr->next;
		i += 1;
	}
	return (-1);
}

