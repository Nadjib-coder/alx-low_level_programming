#include "hash_tables.h"

/**
 * hash_table_set - a function that add or update an element in a hash table.
 * @ht: a pointer to the hash table.
 * @key: the key.
 * @value: value associated with key.
 * Return: (0) failure, (1) otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_t;
	char *value_cp;
	unsigned long int idx, x;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
	{
		return (0);
	}
	value_cp = strdup(value);
	if (value_cp == NULL)
	{
		return (0);
	}
	idx = key_index((const unsigned char *)key, ht->size);
	for (x = idx; ht->array[x]; x++)
	{
		if (strcmp(ht->array[x]->key, key) == 0)
		{
			free(ht->array[x]->value);
			ht->array[x]->value = value_cp;
			return (1);
		}
	}
	new_t = malloc(sizeof(hash_node_t));
	if (new_t == NULL)
	{
		free(value_cp);
		return (0);
	}
	new_t->key = strdup(key);
	if (new_t->key == NULL)
	{
		free(new_t);
		return (0);
	}
	new_t->value = value_cp;
	new_t->next = ht->array[idx];
	ht->array[idx] = new_t;
	return (1);
}

