#include "lists.h"

/**
 * sum_listint - a function that returns the sum of all
 * the data (n) of a listint_t linked list.
 * @head: a pointer to the first node in the list
 * Return: the sum of all the data (N) of the list
 */
int sum_listint(listint_t *head)
{
	listint_t *temp = head;
	size_t sum = 0;

	if (head == NULL)
	{
		return (sum);
	}
	while (temp != NULL)
	{
		sum += temp->n;
		temp = temp->next;
	}
	return (sum);
}

