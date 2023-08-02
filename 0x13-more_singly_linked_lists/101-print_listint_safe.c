#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - a function that prints a linked list of integers
 * @head: pointer to the first node of the list
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow_ptr = head;
	const listint_t *fast_ptr = head;
	size_t count = 0;

	if (head == NULL)
	{
		return (0);
	}
	while (fast_ptr != NULL && fast_ptr->next != NULL)
	{
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
		if (fast_ptr == slow_ptr)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			return (count);
		}
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		count++;
		if (count >= 2 * count)
		{
			printf("-> [%p] %d\n", (void *)head, head->n);
			return (count);
		}
	}
	while (head != NULL)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		count++;
	}

	return (count);
}

