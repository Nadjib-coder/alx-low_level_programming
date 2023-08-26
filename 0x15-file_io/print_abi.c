#include "elf_functions.h"

/**
 * print_abi - Prints the ABI version of an ELF header.
 * @e_idente: A pointer to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *e_idente)
{
	printf(" ABI Version: %d\n",
		e_idente[EI_ABIVERSION]);
}

