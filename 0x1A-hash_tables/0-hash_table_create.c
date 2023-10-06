#include "hash_tables.h"

/**
 * hash_table_create - a function that creates a hash table.
 * @size: The size of the array.
 * Return: a pointer to the new hash table, NULL if an error occurs.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table = malloc(sizeof(hash_table_t));
	unsigned long int idx;

	if (hash_table == NULL)
	{
		return (NULL);
	}
	hash_table->size = size;
	hash_table->array = malloc(sizeof(hash_node_t *) * size);
	if (hash_table->array == NULL)
	{
		return (NULL);
	}
	for (idx = 0; idx < size; idx++)
	{
		hash_table->array[idx] = NULL;
	}
	return (hash_table);
}

