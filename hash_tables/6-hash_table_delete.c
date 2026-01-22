#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to the hash table.
 *
 * Description: Frees all nodes, their keys/values, the array,
 * and finally the hash table structure itself.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *node, *temp;
	unsigned long int i;

	if (ht == NULL)
		return;

	/* 1. Massivin hər bir xanasını gəzirik */
	for (i = 0; i < ht->size; i++)
	{
		/* 2. Əgər həmin xanada Linked List varsa, onu təmizləyirik */
		node = ht->array[i];
		while (node != NULL)
		{
			temp = node->next;
			/* Hər düyünün daxili elementlərini free edirik */
			free(node->key);
			free(node->value);
			free(node);
			node = temp;
		}
	}

	/* 3. Massivin özünü free edirik */
	free(ht->array);

	/* 4. Əsas strukturu free edirik */
	free(ht);
}
