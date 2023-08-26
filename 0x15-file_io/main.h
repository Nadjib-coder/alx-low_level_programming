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

#endif

