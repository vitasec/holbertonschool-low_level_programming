#include "3-calc.h"

/**
 * main - Sade kalkulyator proqramı
 * @argc: Arqumentlerin sayı
 * @argv: Arqumentlerin  massivi
 * Return: 0  dogru digerleri xeta
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;
	int (*op_ptr)(int, int);

	/* 1. Arqument sayini yoxla */
	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	/* 2. Operatorun duzgunluyuü yoxla */
	op_ptr = get_op_func(argv[2]);
	if (op_ptr == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);

	/* 3. Sifira bolmeni yoxla */
	if ((*argv[2] == '/' || *argv[2] == '%') && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}

	result = op_ptr(num1, num2);
	printf("%d\n", result);

	return (0);
}
