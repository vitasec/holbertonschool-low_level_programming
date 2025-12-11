#include "main.h"

/**
 * _strchr - Locates a character in a string
 * @s: Pointer to the string to search
 * @c: Character to locate
 *
 * Return: Pointer to first occurrence of c in s, or NULL if not found
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}

	/* Check for null terminator if c is '\0' */
	if (c == '\0')
		return (s);

	return (NULL);
}
