#include "main.h"

/**
 * print_int - prints an integer to stdout
 * @n: The integer to print
 * Return: void
 */
void print_int(int n)
{
	int temp = n;
	int divisor = 1;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
		temp = n;
	}

	while (temp > 9)
	{
		divisor *= 10;
		temp /= 10;
	}

	while (divisor >= 1)
	{
		_putchar((n / divisor) % 10 + '0');
		divisor /= 10;
	}
}

/**
 * main - Entry point
 *
 * Description: Computes and prints the sum of all the multiples
 * of 3 or 5 below 1024 (excluded).
 * Return: Always 0 (Success)
 */
int main(void)
{
	int sum = 0, i;

	for (i = 1; i < 1024; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}

	print_int(sum);
	_putchar('\n');

	return (0);
}
