#include "lists.h"

/**
 * insert_nodeint_at_index - a function that inserts a new node at
 * a given position.
 * @head: a double pointer to the first node in the list
 * @idx: the index where we have to insert a new node
 * @n: the data value of the new node.
 * Return: a pointer to the new node if (Success), or NULL if failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new, *temp = (*head);

	new = (listint_t *)malloc(sizeof(listint_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->n = n;
	new->next = NULL;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	while (temp && idx >= 1)
	{
		temp = temp->next;
		idx--;
	}
	if (temp == NULL)
	{
		return (NULL);
	}
	new->next = temp->next;
	temp->next = new;
	return (new ? new : NULL);
}

