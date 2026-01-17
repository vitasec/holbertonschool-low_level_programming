#include <stdio.h>
#include "lists.h"

/**
 * print_list - Bağlı siyahının bütün elementlərini çap edir.
 * @h: Siyahının başlanğıc node-una (vaqonuna) pointer.
 *
 * Return: Siyahıdakı node-ların (vaqonların) sayı.
 */
size_t print_list(const list_t *h)
{
	size_t count = 0; /* Vaqonları saymaq üçün dəyişən */

	while (h != NULL) /* Qatar bitənə qədər davam et */
	{
		/* Əgər string NULL-dursa, (nil) çap et */
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			/* Uzunluğu və stringin özünü çap et */
			printf("[%u] %s\n", h->len, h->str);
		}

		count++;      /* Sayı artır */
		h = h->next;  /* Növbəti vaqona keç */
	}

	return (count); /* Ümumi sayı qaytar */
}
