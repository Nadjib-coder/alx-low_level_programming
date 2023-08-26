#include "elf_functions.h"

/**
 * print_version - a function that rints the version of an ELF header.
 * @e_idente: A pointer to an array containing the ELF version.
 */
void print_version(unsigned char *e_idente)
{
	printf(" Version: %d", e_idente[EI_VERSION]);

	switch (e_idente[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

