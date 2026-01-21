#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: Name of the file to read.
 * @letters: Number of letters it should read and print.
 *
 * Return: Actual number of letters read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t n_read, n_written;
	char *buf;

	if (!filename)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (!buf)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buf);
		return (0);
	}

	n_read = read(fd, buf, letters);
	if (n_read == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}

	n_written = write(STDOUT_FILENO, buf, n_read);
	free(buf);
	close(fd);

	if (n_written == -1 || n_written != n_read)
		return (0);

	return (n_written);
}
