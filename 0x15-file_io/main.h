#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>


/* function prototype */
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void print_osabi(Elf64_Ehdr header);
void print_osabi_more(Elf64_Ehdr header);
void print_abiversion(Elf64_Ehdr header);
void print_type(Elf64_Ehdr header);
void print_entry(Elf64_Ehdr header);

/**
 * print_osabi - a function that prints ELF osabi
 * @header: the ELF header
 * Return: Nothing.
 */
void print_osabi(Elf64_Ehdr header)
{
	printf("  OS/ABI:                            ");
	switch (header.e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris");
			break;
		case ELFOSABI_AIX:
			printf("UNIX - AIX");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64");
			break;
		default:
			print_osabi_more(header);
			break;
	}
	printf("\n");
}
/**
 * print_osabi_more - a function that prints ELF osabi more
 * @header: the ELF header
 * Return: Nothing.
 */
void print_osabi_more(Elf64_Ehdr header)
{
	switch (header.e_ident[EI_OSABI])
	{
		case ELFOSABI_MODESTO:
			printf("Novell - Modesto");
			break;
		case ELFOSABI_OPENBSD:
			printf("UNIX - OpenBSD");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App");
			break;
		case ELFOSABI_ARM:
			printf("ARM");
			break;
		default:
			printf("<unknown: %x>", header.e_ident[EI_OSABI]);
			break;
	}
}

/**
 * print_abiversion - prints ELF ABI version
 * @header: the ELF header struct
 * Return: Nothing
 */
void print_abiversion(Elf64_Ehdr header)
{
	printf("  ABI Version:                       %d\n",
			header.e_ident[EI_ABIVERSION]);
}

/**
 * print_type - a function that prints the ELF type
 * @header: the ELF header.
 * Return: Nothing.
 */
void print_type(Elf64_Ehdr header)
{
	char *f = (char *)&header.e_type;
	int x = 0;

	printf("  Type:                              ");
	if (header.e_ident[EI_DATA] == ELFDATA2MSB)
		x = 1;
	switch (f[x])
	{
		case ET_NONE:
			printf("NONE (None)");
			break;
		case ET_REL:
			printf("REL (Relocatable file)");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)");
			break;
		case ET_CORE:
			printf("CORE (Core file)");
			break;
		default:
			printf("<unknown: %x>\n", f[x]);
			break;
	}
	printf("\n");
}

/**
 * print_entry - a function that print the ELF entry point address
 * @header: the ELF header
 * Return: Nothing.
 */
void print_entry(Elf64_Ehdr header)
{
	int len = 0, x = 0;
	unsigned char *f = (unsigned char *)&header.e_entry;

	printf("  Entry point address:               0x");
	if (header.e_ident[EI_DATA] != ELFDATA2MSB)
	{
		x = header.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!f[x])
			x--;
		printf("%x", f[x--]);
		for (; x >= 0; x--)
			printf("%02x", f[x]);
		printf("\n");
	}
	else
	{
		x = 0;
		len = header.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!f[x])
			x++;
		printf("%x", f[x++]);
		for (; x <= len; x++)
			printf("%02x", f[x]);
		printf("\n");
	}
}

#endif

