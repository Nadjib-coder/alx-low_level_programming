#include "main.h"

/* function declaration */
void close_file(int fp);

/**
 * close_file - Closes file descriptors.
 * @fp: The file desciptor to be closed.
 */
void close_file(int fp)
{
	int x;

	x = close(fp);
	if (x == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fp);
		exit(100);
	}
}

/**
 * main - entry point to the program.
 * @argc: the number of argument.
 * @argv: the arguments.
 * Return: 0 (Success).
 */
int main(int argc, char *argv[])
{
	int from, dest, w, r;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}
		dest = open(argv[2], O_WRONLY | O_TRUNC);
		if (dest == -1)
		{
			dest = open(argv[2], O_CREAT | O_WRONLY, 0664);
		}
		w = write(dest, buffer, r);
		if (dest == -1 || w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		r = read(from, buffer, 1024);
		dest = open(argv[2], O_WRONLY | O_APPEND);
	} while (r > 0);
	free(buffer);
	close_file(from);
	close_file(dest);
	return (0);
}

