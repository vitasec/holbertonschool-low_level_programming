#include "main.h"

int _strlen_recursion(char *s);
int check_palindrome(char *s, int start, int end);

/**
 * _strlen_recursion - Returns the length of a string.
 * @s: The string.
 *
 * Return: The length of the string.
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	return (1 + _strlen_recursion(s + 1));
}

/**
 * check_palindrome - Recursively checks if a substring is a palindrome.
 * @s: The string to check.
 * @start: The starting index of the substring.
 * @end: The ending index of the substring.
 *
 * Return: 1 if the substring is a palindrome, 0 otherwise.
 */
int check_palindrome(char *s, int start, int end)
{
	/* 1. Uğurlu Əsas Hal (Base Case - Success): */
	/* Əgər başlanğıc indeksi son indeksi keçirsə  */
	/* yoxlanış uğurla başa çatıb. Sətir palindromdur. */
	if (start >= end)
	{
		return (1);
	}

	/* 2. Uğursuz Əsas Hal (Base Case - Failure): */
	/* Əgər başlanğıc və son mövqelərdəki simvollar fərqlidirsə, */
	/* sətir palindrom deyil. */
	if (s[start] != s[end])
	{
		return (0);
	}

	/* 3. Rekursiv Addım (Recursive Step): */
	/* Əvvəlki və sonrakı simvolları yoxlamaq təkrar çağır. */
	return (check_palindrome(s, start + 1, end - 1));
}

/**
 * is_palindrome - Returns 1 if a string is a palindrome and 0 if not.
 * @s: The string to be checked.
 *
 * Return: 1 if palindrome, 0 if not.
 */
int is_palindrome(char *s)
{
	int len;

	/* 1. Uzunluğu Tapmaq (Length Calculation): */
	len = _strlen_recursion(s);

	/*  uzunluğu 0 və ya 1 olan sətirlər palindromdur. */
	if (len <= 1)
	{
		return (1);
	}

	/* 2. Palindrom Yoxlanışını Başlatmaq (Initiate Check): */
	/* Yoxlanışı sətir başlanğıcı (0) və sonundan (len - 1) başlat. */
	return (check_palindrome(s, 0, len - 1));
}
