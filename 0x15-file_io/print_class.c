#include "elf_functions.h"

/**
 * print_class - Prints the class of an ELF header.
 * @e_idente: A pointer to an array containing the ELF class.
 */
void print_class(unsigned char *e_idente)
{
	printf(" Class: ");

	switch (e_idente[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_idente[EI_CLASS]);
	}
}

