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
void print_osabi(unsigned char *e_idente);
void print_type(unsigned int e_types, unsigned char *e_idente);
void print_entry(unsigned long int e_entry, unsigned char *e_idente);
void close_elff(int elff);
void check_elff(unsigned char *e_idente);
void print_magic(unsigned char *e_idente);
void print_class(unsigned char *e_idente);
void print_data(unsigned char *e_idente);
void print_version(unsigned char *e_idente);
void print_abi(unsigned char *e_idente);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

/**
 * check_elff - a function that checks if a file is an ELF file.
 * @e_idente: pointer to an array contain ELF magic numbers.
 * Return: Nothing.
 */
void check_elff(unsigned char *e_idente)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_idente[i] != 127 &&
		    e_idente[i] != 'E' &&
		    e_idente[i] != 'L' &&
		    e_idente[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * close_elff - a function that closes an ELF file.
 * @elff: The file descriptor of the ELF file.
 * Description: if cannot close exit with code (98).
 * Return: Nothing.
 */
void close_elff(int elff)
{
	if (close(elff) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elff);
		exit(98);
	}
}

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

/**
 * print_version - a function that rints the version of an ELF header.
 * @e_idente: A pointer to an array containing the ELF version.
 */
void print_version(unsigned char *e_idente)
{
	printf(" Version: %d", e_idente[EI_VERSION]);

	switch (e_idente[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

#endif

