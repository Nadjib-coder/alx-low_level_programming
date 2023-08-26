#include "main.h"

/**
 * print_entry - a function that prints the
 * entry point of an ELF header.
 * @e_entry: address of the ELF entry point.
 * @e_idente: a pointer to an array contain  ELF class.
 */
void print_entry(unsigned long int e_entry, unsigned char *e_idente)
{

	printf(" Entry point address: ");
	if (e_idente[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_idente[EI_CLASS] == ELFCLASS32)
	{
		printf("%#x\n", (unsigned int)e_entry);
	}
	else
	{
		printf("%#lx\n", e_entry);
	}
}

