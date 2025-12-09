#include "main.h"

/**
 * puts_half - Prints the second half of a string, followed by a new line.
 * @str: The string to be processed and printed.
 *
 * Description: Calculates length and prints the second half.
 */
void puts_half(char *str)
{
	int len = 0;
	int start_index;

	/* Sətrin uzunluğunu tapmaq */
	while (str[len] != '\0')
	{
		len++;
	}

	/* Uzunluğun cüt olub-olmamasına görə başlanğıc indeksini hesabla */
	if (len % 2 == 0)
	{
		/* Cüt: Məsələn, uzunluq 10 olsa, başlanğıc 10 / 2 = 5 */
		start_index = len / 2;
	}
	else
	{
		/* Tək: Məsələn, uzunluq 9 olsa, başlanğıc (9 + 1) / 2 = 5 */
		/* Bu, n = (L + 1) / 2 qaydasına uyğundur. */
		start_index = (len + 1) / 2;
	}

	/* İkinci yarı simvolları çap etmək */
	while (str[start_index] != '\0')
	{
		_putchar(str[start_index]);
		start_index++;
	}

	/* Yeni sətir əlavə etmək */
	_putchar('\n');
}
