#include "main.h"

/**
 * append_text_to_file - Faylın sonuna mətn əlavə edir.
 * @filename: Faylın adı.
 * @text_content: Əlavə olunacaq mətn.
 *
 * Return: Uğurlu olsa 1, xəta olsa -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, n_written, len = 0;

	if (!filename)
		return (-1);

	/* Əgər mətn varsa, onun uzunluğunu hesabla */
	if (text_content)
	{
		while (text_content[len])
			len++;
	}

	/* O_WRONLY: Yazmaq üçün aç */
	/* O_APPEND: Məlumatı faylın sonuna əlavə et */
	/* Fayl yoxdursa, O_CREAT olmadığı üçün xəta verəcək (-1) */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	/* Əgər əlavə ediləcək mətn varsa, yaz */
	if (text_content)
	{
		n_written = write(fd, text_content, len);
		if (n_written == -1 || n_written != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
