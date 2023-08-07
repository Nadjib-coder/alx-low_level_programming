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
	char *buff;
	ssize_t fp;
	ssize_t ch;
	ssize_t x;

	fp = open(filename, O_RDONLY);
	if (fp == -1)
	{
		return (0);
	}
	buff = malloc(sizeof(char) * letters);
	x = read(fp, bufff, letters);
	ch = write(STDOUT_FILENO, buff, x);

	free(buff);
	close(fp);
	return (ch);
}

