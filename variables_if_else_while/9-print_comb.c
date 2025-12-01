#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num;
	char separator[] = {',', ' '};
	int i;

	for (num = 0; num <= 9; num++)
	{
		putchar(num + '0');
		
		if (num != 9)
		{
			for (i = 0; i < 2; i++)
			{
				putchar(separator[i]);
			}
		}
	}

	putchar('\n');
	return (0);
}
