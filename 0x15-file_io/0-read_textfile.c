#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - a function that reads a text file and
 * prints it to the POSIX standard output.
 * @filename: the pathname of the text file being read.
 * @letters: number of letters to be read
 * Return: (w) actual number of bytes read and printed
 * 0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t fp, ch, x;

	fp = open(filename, O_RDONLY);
	if (fp == -1)
	{
		return (0);
	}
	buffer = malloc(sizeof(char) * letters);
	x = read(fp, buffer, letters);
	ch = write(STDOUT_FILENO, buffer, x);

	free(buffer);
	close(fp);
	return (ch);
}

