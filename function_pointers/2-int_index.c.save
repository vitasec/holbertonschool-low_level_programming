#include "function_pointers.h"

/**
 * int_index - massiv daxilinde axtarir
 * @array: axtaris aparacaq massiv
 * @size: massivdeki elementlerin sayi
 * @cmp: function pointer
 *
 * Return: �elementin indeksi serte uygun
 * Heç bir element tapılmazsa və ya səhv olarsa -1 qaytarır.
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	/* 1. ilkin yoxlanis */
	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	/* 2. Massivin her  bir elementi  */
	for (i = 0; i < size; i++)
	{
		/* 3. Elementi cmp funksiyasina  */
		if (cmp(array[i]) != 0)
		{
			/* Taplan elmentin indeksi */
			return (i);
		}
	}

	/* 4. her sey bitdise  */
	return (-1);
}
