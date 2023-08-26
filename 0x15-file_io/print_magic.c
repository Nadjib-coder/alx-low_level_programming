#include "elf_functions.h"

/**
 * print_magic - a function that prints the magic numbers of an ELF header.
 * @e_idente: A pointer to an array containing the ELF magic numbers.
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *e_idente)
{
	int i;

	printf(" Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_idente[i]);
		if (i == EI_NIDENT - 1)
		{
			printf("\n");
		}
		else
		{
			printf(" ");
		}
	}
}

