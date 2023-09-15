#include "lists.h"

/**
 * add_dnodeint - a function that adds a new node at the
 * beginning of a dlistint_t list.
 * @head: a pointer to the first node in the list.
 * @n: the data for the new node we will add.
 * Return: the address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *temp = malloc(sizeof(dlistint_t));

	if (temp == NULL)
	{
		return (NULL);
	}
	temp->n = n;
	temp->next = (*head);
	temp->prev = NULL;
	if (*head != NULL)
	{
		(*head)->prev = temp;
	}
	(*head) = temp;
	return (temp);
}

