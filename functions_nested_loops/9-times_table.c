#include <unistd.h>

/**
 * times_table - prints the 9 times table, starting with 0
 *
 * Return: void
 */
void times_table(void)
{
	int i, j, result;
	char digit;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			result = i * j;

			/* Her sütun için formatlama */
			if (j != 0)
			{
				write(1, ", ", 2);
				if (result < 10)
					write(1, " ", 1);
			}

			/* İki basamaklı sayı için onlar basamağı */
			if (result >= 10)
			{
				digit = (result / 10) + '0';
				write(1, &digit, 1);
			}

			/* Birler basamağı */
			digit = (result % 10) + '0';
			write(1, &digit, 1);
		}
		write(1, "\n", 1);
	}
}
