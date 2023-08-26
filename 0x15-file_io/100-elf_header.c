#include "main.h"

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
	check_elff(header->e_idente);
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
	close_elff(f);
	return (0);
}
