#include "lists.h"
#include <stdio.h>

/**
 * looped_listint_len - a function that counts the number of
 * unique nodes in a looped listint_t linked list.
 * @head: A pointer to the first node in the listint_t list.
 * Return: 0 if the list is not looped.
 * Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *slow, *fast;
	size_t nodes = 0;

	if (!head || !(head->next))
	{
		return (0);
	}
	slow = head;
	fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			nodes = 1;
			slow = slow->next;
			while (slow != fast)
			{
				nodes++;
				slow = slow->next;
			}
			return nodes;
		}
	}
	return (0);
}

/**
 * print_listint_safe - a function that prints a listint_t
 * linked list.
 * @head: pointer to the first node of the listint_t list.
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, idx = 0;

	nodes = looped_listint_len(head);
	if (nodes == 0)
	{
		for (; head != NULL; nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (idx = 0; idx < nodes; idx++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (nodes);
}

