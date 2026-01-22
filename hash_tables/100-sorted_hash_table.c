#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the hash table.
 *
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
 * @new_node: The node to insert.
 */
void insert_sorted_list(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *temp;

	if (ht->shead == NULL)
	{
		new_node->sprev = NULL;
		new_node->snext = NULL;
		ht->shead = new_node;
		ht->stail = new_node;
		return;
	}
	if (strcmp(new_node->key, ht->shead->key) < 0)
	{
		new_node->sprev = NULL;
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
		return;
	}
	temp = ht->shead;
	while (temp->snext != NULL && strcmp(new_node->key, temp->snext->key) > 0)
		temp = temp->snext;
	new_node->sprev = temp;
	new_node->snext = temp->snext;
	if (temp->snext == NULL)
		ht->stail = new_node;
	else
		temp->snext->sprev = new_node;
	temp->snext = new_node;
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: The sorted hash table.
 * @key: The key.
 * @value: The value.
 *
 * Return: 1 on success, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *temp;
	unsigned long int index;
	char *val_copy;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	val_copy = strdup(value);
	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];
	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
		{
