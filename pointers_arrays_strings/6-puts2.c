#include "main.h"

/**
 * puts2 - Prints every other character of a string, starting with the first.
 * @str: The string to be processed.
 *
 * Description: Prints characters at index 0, 2, 4, 6, etc.,
 * followed by a new line.
 */
void puts2(char *str)
{
	int len = 0;
	int i;

	/* 1. Sətrin uzunluğunu tapmaq */
	while (str[len] != '\0')
	{
		len++;
	}

	/* 2. Hər digər simvolu çap etmək */
	/* Dövr yalnız uzunluq daxilində qalmasını təmin edir */
	for (i = 0; i < len; i += 2)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
