#include <stdio.h>
#include <stdlib.h>

/**
 * main - A program that prints the lowercase aplohabet in reverse
 * Return: 0 (Success)
 */
int main(void)
{
	char ch;

	for (ch = 'z'; ch >= 'a'; ch--)
	{
		putchar(ch);
	}
	putchar('\n');
	return (0);
}

