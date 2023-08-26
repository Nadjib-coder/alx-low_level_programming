#include "main.h"

/**
 * close_elff - a function that closes an ELF file.
 * @elff: The file descriptor of the ELF file.
 * Description: if cannot close exit with code (98).
 * Return: Nothing.
 */
void close_elff(int elff)
{
	if (close(elff) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elff);
		exit(98);
	}
}

