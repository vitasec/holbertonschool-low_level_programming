#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_numbers - Ededleri cap edir, sonda yeni setir qoyur.
 * @separator: Ededler arasinda cap olunacaq simvol (string).
 * @n: Funksiyaya oturulen ededlerin sayi.
 *
 * Return: void.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;

	/* Siyahini basladiriq */
	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		/* Cari ededi cap edirik */
		printf("%d", va_arg(args, int));

		/* Eger separator NULL deyilse VE bu sonuncu eded deyilse */
		if (separator != NULL && i < n - 1)
		{
			printf("%s", separator);
		}
	}

	/* Sonda yeni setir cap edirik */
	printf("\n");

	/* Yaddasi temizleyirik */
	va_end(args);
}
