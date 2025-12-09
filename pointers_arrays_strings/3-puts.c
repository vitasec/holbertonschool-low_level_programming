#include "main.h"

/**
 * _puts - Prints a string followed by a new line to stdout.
 * @str: The string to be printed.
 *
 * Description: Iterates through the string and prints each character
 * until the null terminator is reached, then prints a
 * new line character.
 */
void _puts(char *str)
{
	int i = 0;

	/* Stringin sonuna (null terminatora '\0') çatana qədər dövr edir */
	while (str[i] != '\0')
	{
		_putchar(str[i]); /* Hər bir simvolu çap edir */
		i++;
	}

	/* Simvolları çap etdikdən sonra yeni sətir simvolunu çap edir */
	_putchar('\n');
}
