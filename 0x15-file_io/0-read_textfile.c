#include <main.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * read_and_print_file - reads a text file and prints it to STDOUT
 * @filename: name of file to be read
 * @num_bytes: number of bytes to be read from the file
 *
 * Return: actual number of bytes read and printed, or 0 if function fails
 */
ssize_t read_and_print_file(const char *filename, size_t num_bytes)
{
	int file_descriptor;
	char *buffer;
	ssize_t bytes_read, bytes_written, total_bytes = 0;

	if (filename == NULL)
		return (0);

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);

	buffer = malloc(sizeof(char) * num_bytes);
	if (buffer == NULL)
	{
		close(file_descriptor);
		return (0);
	}

	bytes_read = read(file_descriptor, buffer, num_bytes);
	if (bytes_read == -1)
	{
		close(file_descriptor);
		free(buffer);
		return (0);
	}

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	if (bytes_written == -1 || bytes_written != bytes_read)
	{
		close(file_descriptor);
		free(buffer);
		return (0);
	}

	total_bytes = bytes_written;

	free(buffer);
	close(file_descriptor);

	return (total_bytes);
}

