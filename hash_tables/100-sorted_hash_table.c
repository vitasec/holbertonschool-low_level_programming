#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the hash table.
 * Return: A pointer to the new table, or NULL on failure.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);
	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;
	return (ht);
}

/**
 * insert_sorted_list - Inserts a node into the sorted doubly linked list.
 * @ht: The sorted hash table.
 * @new: The node to insert.
 */
void insert_sorted_list(shash_table_t *ht, shash_node_t *new)
{
	shash_node_t *tmp;

	if (ht->shead == NULL)
	{
		new->sprev = NULL, new->snext = NULL;
		ht->shead = new, ht->stail = new;
		return;
	}
	if (strcmp(new->key, ht->shead->key) < 0)
	{
		new->sprev = NULL, new->snext = ht->shead;
		ht->shead->sprev = new, ht->shead = new;
		return;
	}
	tmp = ht->shead;
	while (tmp->snext != NULL && strcmp(new->key, tmp->snext->key) > 0)
		tmp = tmp->snext;
	new->sprev = tmp, new->snext = tmp->snext;
	if (tmp->snext == NULL)
		ht->stail = new;
	else
		tmp->snext->sprev = new;
	tmp->snext = new;
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: The sorted hash table.
 * @key: The key.
 * @value: The value.
 * Return: 1 on success, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new, *tmp;
	unsigned long int idx;
	char *v_copy;

	if (!ht || !key || !*
