#include "hash_tables.h"

/**
 * shash_table_create - a function that creates a sorted hash table.
 * @size: The size of new sorted hash table.
 * Return: a pointer to the new sorted hash table, or NULL.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *hash_t;
	unsigned long int idx;

	hash_t = malloc(sizeof(shash_table_t));
	if (hash_t == NULL)
	{
		return (NULL);
	}
	hash_t->size = size;
	hash_t->array = malloc(sizeof(shash_node_t *) * size);
	if (hash_t->array == NULL)
	{
		return (NULL);
	}
	for (idx = 0; idx < size; idx++)
	{
		hash_t->array[idx] = NULL;
	}
	hash_t->shead = NULL;
	hash_t->stail = NULL;
	return (hash_t);
}

/**
 * shash_table_set - a function that adds an element to
 * a sorted hash table
 * @ht: a pointer to the sorted hash table
 * @key: the key to add.
 * @value: the value associated with key.
 * Return: (0) failuer, (1) otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_t, *ptr;
	char *value_cp;
	unsigned long int i;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	value_cp = strdup(value);
	if (value_cp == NULL)
	{
		return (0);
	}
	i = key_index((const unsigned char *)key, ht->size);
	ptr = ht->shead;
	while (ptr)
	{
		if (strcmp(ptr->key, key) == 0)
		{
			free(ptr->value);
			ptr->value = value_cp;
			return (1);
		}
		ptr = ptr->snext;
	}
	new_t = malloc(sizeof(shash_node_t));
	if (new_t == NULL)
	{
		free(value_cp);
		return (0);
	}
	new_t->key = strdup(key);
	if (new_t->key == NULL)
	{
		free(value_cp);
		free(new_t);
		return (0);
	}
	new_t->value = value_cp;
	new_t->next = ht->array[i];
	ht->array[i] = new_t;
	if (ht->shead == NULL)
	{
		new_t->sprev = NULL;
		new_t->snext = NULL;
		ht->shead = new_t;
		ht->stail = new_t;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new_t->sprev = NULL;
		new_t->snext = ht->shead;
		ht->shead->sprev = new_t;
		ht->shead = new_t;
	}
	else
	{
		ptr = ht->shead;
		while (ptr->snext != NULL && strcmp(ptr->snext->key, key) < 0)
			ptr = ptr->snext;
		new_t->sprev = ptr;
		new_t->snext = ptr->snext;
		if (ptr->snext == NULL)
			ht->stail = new_t;
		else
			ptr->snext->sprev = new_t;
		ptr->snext = new_t;
	}
	return (1);
}

/**
 * shash_table_get - a function that retrieve the value associated with
 * a key in a sorted hash table.
 * @ht: a pointer to the sorted hash table.
 * @key: the key
 * Return: the value associated with key, or NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int i;

	if (ht == NULL || key == NULL || *key == '\0')
	{
		return (NULL);
	}
	i = key_index((const unsigned char *)key, ht->size);
	if (i >= ht->size)
	{
		return (NULL);
	}
	node = ht->shead;
	while (node != NULL && strcmp(node->key, key) != 0)
	{
		node = node->snext;
	}
	return ((node == NULL) ? NULL : node->value);
}

/**
 * shash_table_print -a function that prints a
 * sorted hash table in order.
 * @ht: a pointer to the sorted hash table.
 * Return: Nothing.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
	{
		return;
	}
	node = ht->shead;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - a function that prints a sorted hash
 * table in reverse order.
 * @ht: a pointer to the sorted hash table to print
 * Return: Nothing.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->stail;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - a function that deletes a sorted hash table.
 * @ht: a pointer to the sorted hash table.
 * Return: Nothing
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *node, *ptr;

	if (ht == NULL)
	{
		return;
	}
	node = ht->shead;
	while (node)
	{
		ptr = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = ptr;
	}
	free(head->array);
	free(head);
}

