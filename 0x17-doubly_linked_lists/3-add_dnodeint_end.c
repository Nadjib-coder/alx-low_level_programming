#include "lists.h"

/**
 * add_dnodeint_end -  a function that adds a new node at the
 * end of a dlistint_t list.
 * @head: a double pointer to the first node of the list
 * @n: the data for the new node we will add.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *ptr = (*head), *temp = malloc(sizeof(dlistint_t));

	if (temp == NULL)
	{
		return (NULL);
	}

	temp->n = n;
	temp->next = NULL;
	temp->prev = NULL;

	if (ptr == NULL)
	{
		(*head) = temp;
		return (temp);
	}
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	temp->prev = ptr;
	ptr->next = temp;

	return (temp);
}

