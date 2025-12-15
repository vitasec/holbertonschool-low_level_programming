#include <stdio.h>
#include <stdlib.h> /* atoi */

/**
 * main - Komut satırından alınan iki sayıyı çarpar.
 * Eğer argüman sayısı 2 değilse (toplamda 3 argüman), Error yazdırır.
 * @argc: Argümanların toplam sayısı.
 * @argv: Argüman string'lerini tutan dizi.
 *
 * Return: İki argüman varsa 0, hata durumunda 1.
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;

	/* 1. Argüman Sayısı Kontrolü: Program adı dahil 3 argüman olmalı. */
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	/* 2. String'den Sayıya Dönüştürme: atoi kullanılır. */
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	/* 3. Çarpma ve Sonucu Yazdırma */
	result = num1 * num2;
	printf("%d\n", result);

	return (0);
}
