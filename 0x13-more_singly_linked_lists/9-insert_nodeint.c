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
	listint_t *new, *temp;

	if (*head == NULL)
	{
		return (NULL);
	}
	temp = (*head);
	new = (listint_t *)malloc(sizeof(listint_t));
	new->n = n;
	new->next = NULL;

	while (temp && idx >= 1)
	{
		temp = temp->next;
		idx--;
	}
	new->next = temp->next;
	temp->next = new;
	return (new ? new : NULL);
}

