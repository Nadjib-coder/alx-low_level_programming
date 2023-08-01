#include "lists.h"

/**
 * delete_nodeint_at_index - a function that deletes the node
 * at index index of a listint_t linked list.
 * @head: a double pointer to the first node in the list.
 * @index: the index of the node we wanna delete.
 * Return: 1 (Success), or -1 (Failed).
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *previous = *head;
	listint_t *current = *head;

	if (*head == NULL)
	{
		return (-1);
	}
	if (index == 0)
	{
		*head = current->link;
		free(current);
		current = NULL;
		return (1);
	}
	index--;
	while (previous && index >= 1)
	{
		previous = previous->next;
		index--;
	}
	if (!previous || !(previous->next))
		return (-1);
	current = previous->next;
	previous->next = current->next;
	free(current);
	return (1);
}

