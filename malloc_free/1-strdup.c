#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL if insufficient memory
 */
char *_strdup(char *str)
{
	char *duplicate;
	unsigned int i, len;

	/* 1. NULL yoxlanışı */
	if (str == NULL)
		return (NULL);

	/* 2. Sətirin uzunluğunu tapırıq */
	len = 0;
	while (str[len] != '\0')
		len++;

	/* 3. Malloc ilə yer ayırırıq (+1 null terminator üçündür) */
	duplicate = malloc(sizeof(char) * (len + 1));

	/* 4. Malloc-un uğurlu olduğunu yoxlayırıq */
	if (duplicate == NULL)
		return (NULL);

	/* 5. Simvolları kopyalayırıq */
	for (i = 0; i <= len; i++)
	{
		duplicate[i] = str[i];
	}

	return (duplicate);
}
