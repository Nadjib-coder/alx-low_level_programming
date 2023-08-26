#include "elf_functions.h"

/**
 * print_data - Prints the data of an ELF header.
 * @e_idente: A pointer to an array containing the ELF class.
 */
void print_data(unsigned char *e_idente)
{
	printf(" Data: ");

	switch (e_idente[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_idente[EI_CLASS]);
	}
}

