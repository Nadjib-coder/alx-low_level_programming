#include "lists.h"

/**
 * find_listint_loop - a function that fiinds the loop in
 * a linked list.
 * @head: a pointer to the first node in a linked list
 * Return: the address of the node where the loop starts, or NULL
 * if failed.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fast = head;

	if (!head)
	{
		return (NULL);
	}
	while (slow && fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (fast);
		}
	}
	return (NULL);
}

