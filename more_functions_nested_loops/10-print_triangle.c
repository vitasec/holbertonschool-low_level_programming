#include "main.h"

/**
 * print_triangle - prints a triangle in the terminal
 * @size: size of the triangle
 *
 * Return: void
 */
void print_triangle(int size)
{
	int i, j, k;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 1; i <= size; i++)
	{
		/* print spaces */
		for (j = size - i; j > 0; j--)
			_putchar(' ');

		/* print '#' */
		for (k = 0; k < i; k++)
			_putchar('#');

		_putchar('\n');
	}
}

