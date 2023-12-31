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
	listint_t *prev = *head;
	listint_t *current = NULL;

	if (*head == NULL)
	{
		return (-1);
	}
	if (index == 0)
	{
		prev = prev->next;
		free(*head);
		*head = prev;
		return (1);
	}
	index--;
	while (prev && index >= 1)
	{
		prev = prev->next;
		index--;
	}
	if (!prev || !(prev->next))
	{
		return (-1);
	}
	current = prev->next;
	prev->next = current->next;
	free(current);
	return (1);
}

