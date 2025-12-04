#include "main.h"

/**
 * print_number - prints an integer using only _putchar
 * @n: number to print
 *
 * Return: void
 */
void print_number(int n)
{
	if (n >= 100)
	{
		_putchar((n / 100) + '0');
		_putchar(((n / 10) % 10) + '0');
		_putchar((n % 10) + '0');
	}
	else if (n >= 10)
	{
		_putchar((n / 10) + '0');
		_putchar((n % 10) + '0');
	}
	else
	{
		_putchar(n + '0');
	}
}

/**
 * print_times_table - prints the n times table, starting with 0
 * @n: the number to generate the table for
 *
 * Return: void
 */
void print_times_table(int n)
{
	int i, j, result;

	if (n < 0 || n > 15)
		return;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			result = i * j;

			if (j == 0)
			{
				print_number(result);
			}
			else
			{
				_putchar(',');
				_putchar(' ');
				if (result < 10)
				{

