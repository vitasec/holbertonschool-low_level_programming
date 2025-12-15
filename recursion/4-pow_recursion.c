#include "main.h"

/**
 * _pow_recursion - Returns the value of x raised to the power of y.
 * @x: The base number.
 * @y: The exponent (power).
 *
 * Return: The value of x^y. Returns -1 if y is negative.
 */
int _pow_recursion(int x, int y)
{
	/* 1. Hata Kontrolü (Error Check): y negatifse -1 döndürülür. */
	if (y < 0)
	{
		return (-1);
	}

	/* 2. Temel Durum (Base Case): x^0 her zaman 1'dir (x != 0 için). */
	if (y == 0)
	{
		return (1);
	}

	/* 3. Özyinelemeli Adım (Recursive Step): x * x^(y-1) */
	/* Bu, x * x * ... (y kez) çarpımını hesaplar. */
	return (x * _pow_recursion(x, y - 1));
}
