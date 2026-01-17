#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: pointer to the head of the list
 * @index: index of the node to return, starting from 0
 *
 * Return: the address of the node at index, or NULL if it doesn't exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int count = 0;

	/* Siyahı bitənə qədər və ya indeksə çatana qədər irəlilə */
	while (head != NULL)
	{
		if (count == index)
			return (head);

		head = head->next;
		count++;
	}

	/* Əgər dövr bitibsə və tapılmayıbsa, deməli indeks mövcud deyil */
	return (NULL);
}
