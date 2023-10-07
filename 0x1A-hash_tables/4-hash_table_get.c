#include "hash_tables.h"

/**
 * hash_table_get - a function that retrieve the value associated with
 * a key in a hash table.
 * @ht: a pointer to the hash table.
 * @key: the key.
 * Return: (NULL) if the key cannot be matched,
 * otherwise the value associated with key in hash table.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node;
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
	node = ht->array[i];
	while (node && strcmp(node->key, key) != 0)
	{
		node = node->next;
	}
	return ((node == NULL) ? NULL : node->value);
}

