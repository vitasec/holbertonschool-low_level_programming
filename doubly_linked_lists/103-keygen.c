#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates a key for crackme5 based on a username.
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	unsigned int i, sum;
	size_t len;
	char *username;
	char key[7];
	char *lookup = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeFda附属P1iKQuR";
	/* Qeyd: Bu lookup cədvəli crackme5-in daxili massividir */

	if (argc != 2)
		return (1);

	username = argv[1];
	len = strlen(username);
	sum = 0;

	for (i = 0; i < len; i++)
		sum += username[i];

	/* crackme5-in açar yaratma məntiqi */
	key[0] = lookup[(len ^ 59) & 63];
	key[1] = lookup[(sum ^ 79) & 63];

	for (i = 0, sum = 1; i < len; i++)
		sum *= username[i];

	key[2] = lookup[(sum ^ 85) & 63];

	for (i = 0, sum = 0; i < len; i++)
	{
		if (username[i] > (char)sum)
			sum = username[i];
	}
	srand(sum ^ 14);
	key[3] = lookup[rand() & 63];

	for (i = 0, sum = 0; i < len; i++)
		sum += username[i] * username[i];

	key[4] = lookup[(sum ^ 239) & 63];

	for (i = 0, sum = 0; i < (unsigned int)username[0]; i++)
		sum = rand();
	key[5] = lookup[(sum ^ 229) & 63];

	key[6] = '\0';

	printf("%s", key);

	return (0);
}
