#include "elf_functions.h"

/**
 * print_type - Prints the type of an ELF header.
 * @e_types: The ELF type.
 * @e_idente: A pointer to an array containing the ELF class.
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
/**
 * print_entry - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_idente: A pointer to an array containing the ELF class.
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
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - Closes an ELF file.
 * @elff: The file descriptor of the ELF file.
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int elff)
{
	if (close(elff) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elff);
		exit(98);
	}
}
