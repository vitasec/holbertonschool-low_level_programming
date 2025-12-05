#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
void print_alphabet(void);
void print_alphabet_x10(void);
int _islower(int c);
int _isalpha(int c);
int print_sign(int n);
int _abs(int);
int print_last_digit(int);
void jack_bauer(void);
void times_table(void);
int add(int, int);
void print_to_98(int n);
void print_int(int n);
/* int _putchar(char c); - Bu təkrar olunduğu üçün silinə bilər, amma yuxarıdakı şərhi istifadə edək. */

/* 🛠️ DƏYİŞİKLİK 1: print_times_table sənədləşməsi */
/**
 * print_times_table - prints the n times table, starting with 0
 * @n: the number to generate the table for
 *
 * Return: void
 */
void print_times_table(int n);

/* _putchar təkrar olunur, onu silmək olar, amma betty üçün əsas deyil. */

/* 🛠️ DƏYİŞİKLİK 2: print_number sənədləşməsi */
/**
 * print_number - prints an integer using only _putchar
 * @n: number to print
 *
 * Return: void
 */
void print_number(int n);

#endif
