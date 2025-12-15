#include <stdio.h>

/**
 * main -  tüm argümanları yazdırır.
 * @argc: Komut satırı argümanlarının sayısı.
 * @argv: Argümanları tutan dizinin işaretçisi.
 *
 * Return: Her zaman 0 (Başarı).
 */
int main(int argc, char *argv[])
{
	int i;

	/*
	 * Argümanları yazdırmak için döngü kur.
	 * Döngü 0'dan başlar  ve argc'den küçük olduğu sürece devam
	 */
	for (i = 0; i < argc; i++)
	{
		/* argv[i] mevcut argüman string'ini içerir. */
		printf("%s\n", argv[i]);
	}

	return (0);
}
