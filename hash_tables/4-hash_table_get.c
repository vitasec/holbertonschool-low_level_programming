#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key.
 * @ht: A pointer to the hash table to look into.
 * @key: The key you are looking for.
 *
 * Return: The value associated with the element,
 * or NULL if key couldn't be found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	/* 1. Açarın olduğu indeksi tapırıq */
	index = key_index((const unsigned char *)key, ht->size);

	/* 2. Həmin indeksdəki ilk düyünə (node) baxırıq */
	node = ht->array[index];

	/* 3. Linked list boyunca açarı axtarırıq */
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	/* Tapılmadısa NULL */
	return (NULL);
}
