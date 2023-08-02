#include "lists.h"
#include <stdio.h>

size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *current = head;
	const listint_t *temp;

	while (current != NULL)
	{
		printf("[%lu] %d\n", count, current->n);
		count++;
		temp = current;
		current  = current->next;
		if (temp <= current)
		{
			printf("Error: Linked list contains a loop\n");
			exit(98);
		}
	}
	return (count);
}

