#include "main.h"

void close_file(int fd);

/**
 * close_file - Closes file descriptors.
 * @fp: The file descriptor to be closed.
 */
void close_file(int fp)
{
	int x = close(fp);

	if (x == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fp);
		exit(100);
	}
}
/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 (Success).
 */
int main(int argc, char *argv[])
{
	int from, dest, r, w;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buff = malloc(sizeof(char) * 1024);
	if (buff == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	from = open(argv[1], O_RDONLY);
	r = read(from, buff, 1024);
	dest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}
		w = write(dest, buff, r);
		if (dest == -1 || w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}
		r = read(from, buff, 1024);
		dest = open(argv[2], O_WRONLY | O_APPEND);
	} while (r > 0);
	free(buff);
	close_file(from);
	close_file(dest);
	return (0);

}

