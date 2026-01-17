#include "lists.h"

/**
 * list_len - Siyahıdakı elementlərin sayını qaytarır.
 * @h: Siyahının başlanğıcına (head) olan pointer.
 *
 * Return: Siyahıdakı elementlərin sayı.
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next; /* Növbəti vaqona keçid */
	}

	return (count);
}
