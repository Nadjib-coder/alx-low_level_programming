#include "main.h"

/**
 * print_type - a function that prints the ELF header.
 * @e_types: ELF type.
 * @e_idente: ELF class.
 * Return: Nothing.
 */
void print_type(unsigned int e_types, unsigned char *e_idente)
{
	if (e_idente[EI_DATA] == ELFDATA2MSB)
		e_types >>= 8;

	printf(" Type: ");
	switch (e_types)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_types);
	}
}

