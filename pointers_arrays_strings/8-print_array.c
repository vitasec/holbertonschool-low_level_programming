#include "main.h"
#include <stdio.h>

/**
 * print_array - Prints n elements of an array of integers.
 * @a: The array of integers.
 * @n: The number of elements to be printed.
 *
 * Description: Elements are separated by a comma and a space,
 * except for the last element.
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);

		/* Yalnız sonuncu elementdən əvvəl vergül və boşluq əlavə et */
		if (i != n - 1)
		{
			printf(", ");
		}
	}

	printf("\n");
}
