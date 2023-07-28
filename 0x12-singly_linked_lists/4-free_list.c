#include "lists.h"

/**
 * free_list -a function that frees a linked list
 * @head: the linked list (list_t) to be freed
 * Return: Nothing.
 */
void free_list(list_t *head)
{
	list_t *ptr;

	while (head)
	{
		ptr = head->next;
		free(head->str);
		free(head);
		head = ptr;
	}
}

