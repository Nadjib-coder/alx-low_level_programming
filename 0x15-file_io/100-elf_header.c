#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>

void check_elf(unsigned char *e_ident);
void print_field(const char *name, const char *format, ...);
void close_elf(int elf);
void open_and_read_elf(const char *filename, Elf64_Ehdr *header);
void print_elf_info(const Elf64_Ehdr *header);

/**
 * check_elf - a function that check the file if it is a elf file
 * @e_ident: an array of characters.
 * Return: Nothing.
 */
void check_elf(unsigned char *e_ident)
{
	if (e_ident[0] != 0x7f || e_ident[1] != 'E' || e_ident[2] != 'L'
			|| e_ident[3] != 'F')
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
}

/**
 * print_field - a function that print field
 * @name: the name of the field
 * @format: the format of the field
 * Return: Nothing.
 */
void print_field(const char *name, const char *format, ...)
{
	va_list args;

	va_start(args, format);
	printf(" %s: ", name);
	vprintf(format, args);
	printf("\n");
	va_end(args);
}

/**
 * close_elf - a function that close elf file
 * @elf: elf file d.
 * Return: Nothing.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		perror("Error: Can't close file descriptor");
		exit(98);
	}
}

/**
 * open_and_read_elf - a function that open and the information
 * of elf file
 * @filename: the name of the file
 * @header: the header of the file
 * Return: Nothing.
 */
void open_and_read_elf(const char *filename, Elf64_Ehdr *header)
{
	int elf = open(filename, O_RDONLY);

	if (elf == -1)
	{
		perror("Error: Can't open file");
		exit(98);
	}
	if (read(elf, header, sizeof(*header)) != sizeof(*header))
	{
		perror("Error: Failed to read ELF header");
		close_elf(elf);
		exit(98);
	}
	close_elf(elf);
}

/**
 * print_elf_info - a function that print the header elf info
 * @header: the header file of elf file.
 * Return: NOthing.
 */
void print_elf_info(const Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	print_field("Magic", "%.4s", header->e_ident);
	print_field("Class", "%s", header->e_ident[EI_CLASS] == ELFCLASS32 ?
			"ELF32" : "ELF64");
	print_field("Data", "%s", header.e_ident[EI_DATA] == ELFDATA2LSB ?
			"2's complement, little endian" :
			(header.e_ident[EI_DATA] == ELFDATA2MSB ?
			"2's complement, big endian" : "Unknown"));
	print_field("Version", "%d", header.e_ident[EI_VERSION]);
	print_field("OS/ABI", "%s", header.e_ident[EI_OSABI] == ELFOSABI_NONE ?
			"UNIX - System V" :
			(header.e_ident[EI_OSABI] == ELFOSABI_LINUX ? "UNIX - Linux" : "Unknown"));
	print_field("ABI Version", "%d", header.e_ident[EI_ABIVERSION]);
	type_str = "Unknown";
}

/**
 * main - entry point
 * @argc: the number of argument
 * @argv: an array of argument
 * Return: 0 (Success), or 1 (failed).
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <elf_file>\n", argv[0]);
		return (1);
	}
	open_and_read_elf(argv[1], &header);
	check_elf(header.e_ident);
	print_elf_info(&header);
	return (0);
}

