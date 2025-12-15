#include "main.h"

/**
 * _puts_recursion - Prints a string, followed by a new line, using recursion.
 * @s: The string to be printed.
 *
 * Return: void
 */
void _puts_recursion(char *s)
{
	/* Temel Durum (Base Case): Dizenin sonuna ulaşıldı (null karakter) */
	if (*s == '\0')
	{
		/* Yeni satır karakterini yazdır */
		_putchar('\n');
		return;
	}

	/* Özyinelemeli Adım (Recursive Step): */
	/* 1. Mevcut karakteri yazdır */
	_putchar(*s);
	/* 2. Fonksiyonu dizideki bir sonraki karakter için tekrar çağır */
	_puts_recursion(s + 1);
}
