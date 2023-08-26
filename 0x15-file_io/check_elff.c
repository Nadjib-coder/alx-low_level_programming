#include "main.h"

/**
 * check_elf - a function that checks if a file is an ELF file.
 * @e_ident: pointer to an array contain ELF magic numbers.
 * Return: Nothing.
 */
void check_elff(unsigned char *e_idente)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 &&
		    e_ident[i] != 'E' &&
		    e_ident[i] != 'L' &&
		    e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

