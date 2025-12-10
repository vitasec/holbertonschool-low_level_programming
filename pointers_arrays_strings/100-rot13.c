#include "main.h"

/**
 * rot13 - Encodes a string using ROT13 cipher.
 * @s: The string to be encoded.
 *
 * Return: A pointer to the resulting string.
 */
char *rot13(char *s)
{
	int i;
	int j;
	char map_in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char map_out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	/* Loop 1: Iterate through the input string until the null terminator */
	for (i = 0; s[i] != '\0'; i++)
	{
		/* Loop 2: Iterate through the mapping arrays (52 characters total) */
		for (j = 0; j < 52; j++)
		{
			/* Check for a match using the single allowed 'if' statement */
			if (s[i] == map_in[j])
			{
				/* Replace the character with its ROT13 counterpart */
				s[i] = map_out[j];
				/* Break the inner loop since the character has been processed */
				break;
			}
		}
	}

	return (s);
}
