#include "main.h"

/**
 * print_last_digit - Prints the last digit of a number
 * @n: number to check
 *
 * Return: value of the last digit
 */
int print_last_digit(int n)
{
	int last;

	if (n < 0)
		n = -n;

	last = n % 10;

	_putchar(last + '0');

	return (last);
}

