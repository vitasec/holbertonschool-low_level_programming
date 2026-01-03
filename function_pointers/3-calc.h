#ifndef CALC_H
#define CALC_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct op - Operator  strukturu
 * @op: Operator simvolu
 * @f: hemin operatora uygun funksiya pointer
 */
typedef struct op
{
	char *op;
	int (*f)(int a, int b);
} op_t;

/* Riyazi  funksiyaları */
int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/* Funksiyanim funksiya */
int (*get_op_func(char *s))(int, int);

#endif /* CALC_H */
