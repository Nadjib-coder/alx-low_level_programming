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

/**
 * print_osabi - Prints the OS/ABI of an ELF header.
 * @e_idente: A pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *e_idente)
{
	printf(" OS/ABI: ");

	switch (e_idente[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_idente[EI_OSABI]);
	}
}

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

/**
 * main - afunction that displays the information of
 * ELF header.
 * @argc: number of arguments
 * @argv: array of pointer to the arguments.
 * Return: 0 (Success).
 * Description: If the file is not an ELF File or
 * the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int f = open(argv[1], O_RDONLY), r;

	if (f == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elff(f);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(f, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elff(f);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	check_elff(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	printf(" ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);
	free(header);
	close_elff(f);
	return (0);
}

