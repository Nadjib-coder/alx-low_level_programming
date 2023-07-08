#include "main.h"
#include <stdio.h>

/**
 * main - a program that prints its name,
 * followed by a new line.
 * @argc: number of command line arguments passed to
 * the program
 * @argv: an array of string that contains the
 * command line arguments
 * Return: 0 (Success).
 */
int main(int args, char *argv[] __attribute__((unused)))
{
	int num = args - 1;
	printf("%d\n", num);
	return (0);
}

