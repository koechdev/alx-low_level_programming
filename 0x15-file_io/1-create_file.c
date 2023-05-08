#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 *
 * @filename: pointer to the name of the file to be read
 * @letters: number of letters to read and print
 *
 * Return: the actual number of letters read and printed, 0 if function fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t file_descriptor, write_return, read_return, total_bytes_read;

	if (filename == NULL)
		return (0);

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		close(file_descriptor);
		return (0);
	}

	read_return = read(file_descriptor, buf, letters);
	if (read_return == -1)
	{
		free(buf);
		close(file_descriptor);
		return (0);
	}

	write_return = write(STDOUT_FILENO, buf, read_return);
	if (write_return == -1 || write_return != read_return)
	{
		free(buf);
		close(file_descriptor);
		return (0);
	}

	total_bytes_read = (ssize_t)read_return;

	free(buf);
	close(file_descriptor);

	return (total_bytes_read);
}

