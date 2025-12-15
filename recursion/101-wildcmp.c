#include "main.h"

/**
 * wildcmp - Compares two strings, considering '*' as a wildcard.
 * @s1: The first string (regular).
 * @s2: The second string (may contain '*').
 *
 * Return: 1 if strings can be considered identical, 0 otherwise.
 */
int wildcmp(char *s1, char *s2)
{
	/* 1. Her İki Dize de Sona Erdiyse: Mükemmel Eşleşme */
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (1);
	}

	/* 2. s2'de '*' Karakteri Kontrolü */
	if (*s2 == '*')
	{
		/* Ardışık '*' karakterlerini atla */
		while (*(s2 + 1) == '*')
		{
			s2++;
		}

		/* Yol A: '*' boş dizeyi temsil eder (s2'de ilerle) VEYA */
		/* Yol B: '*' bir veya daha fazla karakteri temsil eder (s1'de ilerle) */
		return (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)));
	}

	/* 3. s1 bitti, ama s2 bitmediyse (ve s2'de '*' yok): Başarısızlık */
	if (*s1 == '\0' && *s2 != '\0')
	{
		return (0);
	}

	/* 4. Normal Karakter Eşleşmesi */
	if (*s1 == *s2)
	{
		return (wildcmp(s1 + 1, s2 + 1));
	}

	/* 5. Genel Başarısızlık */
	return (0);
}
