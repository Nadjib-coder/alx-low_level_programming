#include "hash_tables.h"

/**
 * key_index - a function to Get the index at which a key or value
 * pair
 * @key: The key
 * @size: size of the array
 * Return: index of the key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}

