#include "lists.h"

/**
 * pop_listint - a function that deletes the head node of a
 * listint_t linked list.
 * @head: a double pointer to the first node in the list.
 * Return: the head node’s data (n).
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int num;

	if (head == NULL || *head == NULL)
	{
		return (0);
	}
	num = (*head)->n;
	temp = (*head)->next;
	free(*head);
	(*head) = temp;

	return (num);
}
