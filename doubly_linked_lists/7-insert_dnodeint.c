#include "lists.h"

/**
 * insert_dnodeint_at_index - verilmiş indeksə yeni node əlavə edir
 * @h: siyahının başlanğıcına olan double pointer
 * @idx: yeni node-un əlavə ediləcəyi indeks (0-dan başlayır)
 * @n: yeni node-un daxilindəki rəqəm
 *
 * Return: yeni node-un ünvanı, yaxud uğursuz olarsa NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *temp = *h;
	unsigned int i;

	/* 1. Əgər indeks 0-dırsa, bu siyahının əvvəlinə əlavə etməkdir */
	if (idx == 0)
		return (add_dnodeint(h, n));

	/* 2. Verilən indeksdən bir addım əvvələ qədər siyahını gəz */
	for (i = 0; temp != NULL && i < idx - 1; i++)
		temp = temp->next;

	/* 3. Əgər siyahı göstərilən indeksə çatmadan bitibsə */
	if (temp == NULL)
		return (NULL);

	/* 4. Əgər temp sonuncu node-dursa, deməli siyahının sonuna əlavə edirik */
	if (temp->next == NULL)
		return (add_dnodeint_end(h, n));

	/* 5. Ortaya əlavə etmək üçün yeni node yarat */
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;

	/* 6. Bağlantıları qur (Ən vacib hissə) */
	new->next = temp->next;      /* Yeni node özündən sonrakını tanıyır */
	new->prev = temp;            /* Yeni node özündən əvvəlkini tanıyır */
	temp->next->prev = new;      /* Sonrakı node artıq yeni node-u tanıyır */
	temp->next = new;            /* Əvvəlki node artıq yeni node-u tanıyır */

	return (new);
}
