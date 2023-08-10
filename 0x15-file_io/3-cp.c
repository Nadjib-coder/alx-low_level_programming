#include "main.h"

/**
 * close_file - Closes file descriptors.
 * @fb: The file desciptor to be closed.
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
 * main - entry point
 * @argc: the number of argument.
 * @argv: the arguments.
 * Return 0 (Success).
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
	if (from == -1 || r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		exit(98);
	}
	dest = open(argv[2], O_WRONLY | O_TRUNC);
	if (dest == -1)
	{
		dest = open(argv[2], O_CREAT, 0644);
	}
	w = write(dest, buffer, r);
	if (dest == -1 || w == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		free(buffer);
		exit(99);
	}
	free(buffer);
	close_file(from);
	close_file(dest);
	return (0);
}

