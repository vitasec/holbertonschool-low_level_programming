#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The integer value extracted from the string.
 * Returns 0 if no number is found.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int result = 0;
	int num_started = 0;

	while (*s != '\0')
	{
		if (*s == '-')
		{
			sign *= -1;
		}
		else if (*s == '+')
		{
			/* No change in sign, just proceed */
		}
		else if (*s >= '0' && *s <= '9')
		{
			num_started = 1;

			result = (result * 10) + (*s - '0');
		}
		else if (num_started)
		{
			break;
		}

		s++;
	}

	return (result * sign);
}
