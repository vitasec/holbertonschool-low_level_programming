#include <stdio.h>

/**
 * main - Prints all possible different combinations of two digits
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
			putchar(i + '0');  /* 1st putchar: birinci rəqəm */
			putchar(j + '0');  /* 2nd putchar: ikinci rəqəm */

			if (i == 8 && j == 9)
				putchar('\n');  /* 3rd putchar: sonuncu kombinasiyada yeni sətir */
			else
			{
				putchar(',');   /* 3rd putchar: vergül */
				putchar(' ');   /* 4th putchar: boşluq */
			}
		}
	}

	return (0);
}

