#include "hash_tables.h"

/**
 * hash_table_print - a function that prints a hash table.
 * @ht: A pointer to the hash table
 * Return: Nothing.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int index;
	unsigned char flag = 0;

	if (ht == NULL)
	{
		return;
	}
	printf("{");
	for (idx = 0; idx < ht->size; idx++)
	{
		if (ht->array[idx] != NULL)
		{
			if (flag == 1)
				printf(", ");
			node = ht->array[idx];
			while (node != NULL)
			{
				printf("'%s': '%s'", node->key, node->value);
				node = node->next;
				if (node != NULL)
				{
					printf(", ");
				}
			}
			flag = 1;
		}
	}
	printf("}\n");
}

