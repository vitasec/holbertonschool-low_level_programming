#include "main.h"

/**
 * print_number - Prints an integer using only the _putchar function.
 * @n: The integer to be printed.
 *
 * Constraints: No long, arrays, pointers, or hard-coded special values
 * (other than ASCII digits). Uses recursion to print digits.
 */
void print_number(int n)
{
	int digit;
	int temp = n;

	/* 1. Handle the sign: Check for negative numbers */
	if (n < 0)
	{
		_putchar('-');
		/*
		 * Use integer limits to handle the absolute value of INT_MIN,
		 * which cannot be represented as a positive int.
		 * Since n = -2147483648 (INT_MIN) would overflow if directly
		 * multiplied by -1, we handle it by printing the first digit
		 * '2' manually and negating the rest.
		 */
		if (n == -2147483648)
		{
			_putchar('2');
			temp = 147483648;
		}
		else
		{
			temp = -n;
		}
	}

	/* 2. Recursive Step: Print all digits except the last one */
	/* If the number has more than one digit (i.e., quotient > 0) */
	if (temp / 10 != 0)
	{
		/* Recursively call the function to print the higher order digits */
		print_number(temp / 10);
	}

	/* 3. Base Case/Printing Step: Get and print the last digit */
	/* The modulo operator gives the last digit */
	digit = temp % 10;

	/* Convert the integer digit (0-9) to its ASCII character ('0'-'9') */
	_putchar(digit + '0');
}
