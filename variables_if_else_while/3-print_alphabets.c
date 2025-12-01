#include <stdio.h>

/**
 * main - Prints the alphabet in lowercase and then in uppercase
 *
 * Return: Always 0
 */
int main(void)
{
	int ch;

	/* lowercase letters */
	for (ch = 'a'; ch <= 'z'; ch++)
		putchar(ch);

	/* uppercase letters */
	for (ch = 'A'; ch <= 'Z'; ch++)
		putchar(ch);

	/* new line */
	putchar('\n');

	return (0);
}

