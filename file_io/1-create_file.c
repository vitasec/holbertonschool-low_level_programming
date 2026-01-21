#include "main.h"

/**
 * create_file - Creates a file and writes text into it.
 * @filename: The name of the file to create.
 * @text_content: A NULL terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, n_written, len = 0;

	if (!filename)
		return (-1);

	/* Mətnin uzunluğunu hesablayırıq (strlen istifadə etmədən) */
	if (text_content)
	{
		while (text_content[len])
			len++;
	}

	/* O_CREAT: Yoxdursa yarat */
	/* O_WRONLY: Yalnız yazmaq üçün aç */
	/* O_TRUNC: Varsa içini boşalt */
	/* 0600: Sadece sahibinə oxuma-yazma icazəsi ver */
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

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
