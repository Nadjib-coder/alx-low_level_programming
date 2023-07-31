#include "lists.h"

/**
 * get_nodeint_at_index - a function that returns the nth node of
 * a listint_t linked list.
 * @head: a pointer to the first node in the list.
 * @index: the index of the node to return
 * Return: pointer to the node we're looking for, or NULL.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{

	listint_t *temp = head;

	while (temp && index >= 1)
	{
		temp = temp->next;
		index--;
	}
	return (temp ? temp : NULL);
}

