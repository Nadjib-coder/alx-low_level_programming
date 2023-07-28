#include "lists.h"
#include <string.h>
#include <stdlib.h>


/**
 * add_node -  a function that adds a new node at
 * the beginning of a list_t list.
 * @head: double pointer to the list_t
 * @str: new dublicated string to add.
 * Return: the addres of new node (Success) or
 * NULL if fail.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	new_node = (list_t *)malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	else
	{
		new_node->str = strdup(str);
		new_node->len = length;
		new_node->next = (*head);
		(*head) = new_node;
	}
	return (*head);
}

