#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list
 * @head: pointer to the head of the doubly linked list
 *
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *next_node;

	while (head != NULL)
	{
		/* 1. Növbəti node-un ünvanını yadda saxla */
		next_node = head->next;

		/* 2. Hazırkı node-u yaddaşdan sil */
		free(head);

		/* 3. Saxladığımız növbəti node-u yeni başlanğıc et */
		head = next_node;
	}
}
