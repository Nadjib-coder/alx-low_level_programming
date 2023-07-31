#include "lists.h"

/**
 * free_listint2 - a function that frees a listint_t list.
 * @head: a double pointer to the first node in the list.
 * Return: Nothing.
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
	 head = NULL;
}

