#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers.
 * @min: the minimum value (included)
 * @max: the maximum value (included)
 *
 * Return: pointer to the newly created array, or NULL if fails
 */
int *array_range(int min, int max)
{
	int *array;
	int i, size;

	if (min > max)
		return (NULL);

	/* 1. Elementlərin sayını hesablayırıq */
	size = max - min + 1;

	/* 2. Tam ədədlər massivi üçün yaddaş ayırırıq */
	array = malloc(sizeof(int) * size);

	if (array == NULL)
		return (NULL);

	/* 3. Massivi min-dən max-a qədər rəqəmlərlə doldururuq */
	for (i = 0; i < size; i++)
	{
		array[i] = min++;
	}

	return (array);
}
