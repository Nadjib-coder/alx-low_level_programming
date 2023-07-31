#include "lists.h"

/**
 * add_nodeint_end - a function that adds a new node at the
 * end of a listint_t list.
 * @head: double pointer to the first node in the linst
 * @n: data integer
 * Return: a pointer to tha last new node.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{

	listint_t *temp, *new = (listint_t *)malloc(sizeof(listint_t));

	if (new == NULL)
	{
		return (NULL);
	}

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		(*head) = new;
		return (new);
	}
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
	return (new);
}

