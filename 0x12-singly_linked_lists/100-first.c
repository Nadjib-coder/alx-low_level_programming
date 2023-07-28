#include <stdio.h>

/* declaring the function */
void before_main(void)__attribute__((constructor));

/**
 * before_main - a function that print somthing
 * to the standard output befor the main
 * function excuted
 * Return: Nothing.
 */
void before_main(void)
{
	printf("You're beat! and yet, you must allow"
		"\nI bore my house upon my back!\n");
}

