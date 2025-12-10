#include "main.h"
#include <stdio.h>

/**
 * print_buffer - Prints buffer
 * @b: Buffer
 * @size: Size
 */
void print_buffer(char *b, int size)
{
	int i, j;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);

		for (j = 0; j < 10; j++)
		{
			if (i + j < size)
				printf("%02x", b[i + j] & 0xff);
			else
				printf("  ");
			if (j % 2)
				printf(" ");
		}

		printf(" ");

		for (j = 0; j < 10 && i + j < size; j++)
			printf("%c", (b[i + j] >= 32 && b[i + j] <= 126) ? b[i + j] : '.');

		printf("\n");
	}
}
