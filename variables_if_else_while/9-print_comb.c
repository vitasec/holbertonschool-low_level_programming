#include <stdio.h>

/**
 * main - Prints all possible combinations of single-digit numbers
 *
 * Return: Always 0
 */
int main(void)
{
	int i, j;

	for (i = 0; i <= 8; i++)
	{
		for (j = i + 1; j <= 9; j++)
		{
			putchar(i + '0');  /* 1st putchar */
			putchar(j + '0');  /* 2nd putchar */

			if (!(i == 8 && j == 9))
			{
				putchar(',');   /* 3rd putchar */
				putchar(' ');   /* 4th putchar */
			}
			else
				putchar('\n');  /* 4th putchar əvəzinə yeni sətir son kombinasiyada */
		}
	}

	return (0);
}

