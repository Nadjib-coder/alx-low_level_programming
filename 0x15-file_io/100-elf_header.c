#include "main.h"

void print_osabi_more(Elf64_Ehdr header);

/**
 * print_magic - a function that prints ELF mafic bytes.
 * @header: the ELF header.
 * Return: Nothing.
 */
void print_magic(Elf64_Ehdr header)
{
	int x;

	printf("  Magic:   ");
	for (x = 0; x < EI_NIDENT; x++)
	{
		printf("%2.2x%s", header.e_ident[x], x == EI_NIDENT - 1 ? "\n" : " ");
	}
}

/**
 * print_class - a function that prints ELF class.
 * @header: the ELF header.
 * Return: Nothing.
 */
void print_class(Elf64_Ehdr header)
{
	printf("  Class:                             ");
	switch (header.e_ident[EI_CLASS])
	{
		case ELFCLASS64:
			printf("ELF64");
			break;
		case ELFCLASS32:
			printf("ELF32");
			break;
		case ELFCLASSNONE:
			printf("none");
			break;
	}
	printf("\n");
}
/**
 * print_data - a function that print ELF data.
 * @header: the ELF header.
 * Return: Nothing.
 */
void print_data(Elf64_Ehdr header)
{
	printf("  Data:                              ");
	switch (header.e_ident[EI_DATA])
	{
		case ELFDATA2MSB:
			printf("2's complement, big endian");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian");
			break;
		case ELFDATANONE:
			printf("none");
			break;
	}
	printf("\n");
}

/**
 * print_version - a function that print ELF version.
 * @header: the ELF header.
 * Return: Nothing.
 */
void print_version(Elf64_Ehdr header)
{
	printf("  Version:                           %d", header.e_ident[EI_VERSION]);
	switch (header.e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)");
			break;
		case EV_NONE:
			printf("%s", "");
		break;
		break;
	}
	printf("\n");
}

/**
 * main - a program that displays the information contained
 * in the ELF header at the start of an ELF file.
 * @argc: the number fo arguments
 * @argv: the arguments
 * Return: 1 (Success), 0 (failure).
 */
int main(int argc, char **argv)
{
	int f;
	Elf64_Ehdr header;
	ssize_t c;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n"), exit(98);
	f = open(argv[1], O_RDONLY);
	if (f == -1)
		dprintf(STDERR_FILENO, "Can't read from file: %s\n", argv[1]), exit(98);
	c = read(f, &header, sizeof(header));
	if (c < 1 || c != sizeof(header))
		dprintf(STDERR_FILENO, "Can't read from file %s\n", argv[1]), exit(98);
	if (header.e_ident[0] == 0x7f && header.e_ident[1] == 'E' &&
			header.e_ident[2] == 'L' &&
			header.e_ident[3] == 'F')
	{
		printf("ELF Header:\n");
	}
	else
		dprintf(STDERR_FILENO, "Not ELF file: %s\n", argv[1]), exit(98);
	print_magic(header);
	print_class(header);
	print_data(header);
	print_version(header);
	print_osabi(header);
	print_abiversion(header);
	print_type(header);
	print_entry(header);
	if (close(f))
		dprintf(STDERR_FILENO, "Error closing file descriptor: %d\n", f), exit(98);
	return (EXIT_SUCCESS);
}

