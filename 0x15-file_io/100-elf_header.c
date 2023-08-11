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

void check_elf(unsigned char *e_ident)
{
	if (e_ident[0] != 0x7f || e_ident[1] != 'E' || e_ident[2] != 'L' || e_ident[3] != 'F')
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
}

void print_field(const char *name, const char *format, ...)
{
	va_list args;

	va_start(args, format);
	printf(" %s: ", name);
	vprintf(format, args);
	printf("\n"); 
	va_end(args);
}

void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		perror("Error: Can't close file descriptor");
		exit(98);
	}
}

int main(int argc, char *argv[])
{
	int elf;
	const char *type_str;

	Elf64_Ehdr header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <elf_file>\n", argv[0]);
		return 1;
	}
	elf = open(argv[1], O_RDONLY);
	if (elf == -1)
	{
		perror("Error: Can't open file");
		return 1;
	}
	if (read(elf, &header, sizeof(header)) != sizeof(header))
	{
		perror("Error: Failed to read ELF header");
		close_elf(elf);
		return 1;
	}
	check_elf(header.e_ident);
	printf("ELF Header:\n");
	print_field("Magic", "%.4s", header.e_ident);
	print_field("Class", "%s", header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	print_field("Data", "%s", header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian"		:(header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "Unknown"));
	print_field("Version", "%d", header.e_ident[EI_VERSION]);
	print_field("OS/ABI", "%s", header.e_ident[EI_OSABI] == ELFOSABI_NONE ? "UNIX - System V" :
			(header.e_ident[EI_OSABI] == ELFOSABI_LINUX ? "UNIX - Linux" : "Unknown"));
	print_field("ABI Version", "%d", header.e_ident[EI_ABIVERSION]);
	type_str = "Unknown";
	if (header.e_type == ET_NONE)
	{
		type_str = "None";
	}
	else if (header.e_type == ET_REL)
	{
		type_str = "Relocatable file";
	}
	else if (header.e_type == ET_EXEC)
	{
		type_str = "Executable file";
	}
	else if (header.e_type == ET_DYN)
	{
		type_str = "Shared object file";
	}
	else if (header.e_type == ET_CORE)
	{
		type_str = "Core file";
	}
	print_field("Type", "%s", type_str);
	if (header.e_ident[EI_CLASS] == ELFCLASS32)
	{
		print_field("Entry point address", "0x%x", (unsigned int)header.e_entry);
	}
	else
	{
		print_field("Entry point address", "0x%lx", header.e_entry);
	}
	close_elf(elf);
	return 0;
}

