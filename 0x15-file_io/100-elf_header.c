#include "elf_functions.h"

/**
 * main - Displays the information contained in the
 * ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 * the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int f, r;

	f = open(argv[1], O_RDONLY);
	if (f == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(f);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_idente);
	printf("ELF Header:\n");
	print_magic(header->e_idente);
	print_class(header->e_idente);
	print_data(header->e_idente);
	print_version(header->e_idente);
	print_osabi(header->e_idente);
	print_abi(header->e_idente);
	print_type(header->e_types, header->e_idente);
	print_entry(header->e_entry, header->e_idente);

	free(header);
	close_elf(f);
	return (0);
}
