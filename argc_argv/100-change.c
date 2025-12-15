#include <stdio.h>
#include <stdlib.h> /* atoi için */

/**
 * main - Prints the minimum number of coins to make change for an amount.
 * Available coins: 25, 10, 5, 2, 1 cents.
 * @argc: The number of command line arguments.
 * @argv: An array of argument strings.
 *
 * Return: 0 on success, 1 on error (if argc != 2).
 */
int main(int argc, char *argv[])
{
	int cents;
	int coins[] = {25, 10, 5, 2, 1};
	int num_coins = 0;
	int i;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	for (i = 0; i < 5; i++)
	{
		num_coins += cents / coins[i];

		cents %= coins[i];
	}

	printf("%d\n", num_coins);

	return (0);
}
