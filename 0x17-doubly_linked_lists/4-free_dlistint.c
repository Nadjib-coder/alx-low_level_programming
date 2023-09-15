#include "lists.h"

/**
 * free_dlistint - a function that frees a dlistint_t list.
 * @head: a pointer to the first node in the list.
 * Return: Nothing.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current = head, *prev = head;

	if (head == NULL)
	{
		free(head);
	}
	while (current != NULL && prev != NULL && prev->next != NULL)
	{
		current = current->next;
		free(prev->n);
		free(prev);
		prev = curent;
	}
	free(current->n);
	free(current);
}

