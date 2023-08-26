#ifndef ELF_FUNCTIONS_H
#define ELF_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void check_elf(unsigned char *e_idente);
void print_magic(unsigned char *e_idente);
void print_class(unsigned char *e_idente);
void print_data(unsigned char *e_idente);
void print_version(unsigned char *e_idente);
void print_abi(unsigned char *e_idente);
void print_osabi(unsigned char *e_idente);
void print_type(unsigned int e_types, unsigned char *e_idente);
void print_entry(unsigned long int e_entry, unsigned char *e_idente);
void close_elf(int elff);

#endif

