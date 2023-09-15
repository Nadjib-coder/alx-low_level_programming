#include "lists.h"

/**
 * sum_dlistint -  a function that returns the sum of all the data (n)
 * of a dlistint_t linked list.
 * @head: a pointer to the first node of the list.
 * Return: the sum of all the data (n) of a linked list.
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *ptr = head;
	int sum = 0;

	if (ptr == NULL)
	{
		return (sum);
	}
	while (ptr != NULL)
	{
		sum += ptr->n;
		ptr = ptr->next;
	}
	return (sum);
}

