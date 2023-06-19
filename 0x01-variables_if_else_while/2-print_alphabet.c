#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints the alphabet in lower case
 * Return: 0 Always
 */
int main(void)
{
	char ch = 'a';

	while (ch <= 'z')
	{
		putchar(ch);
		ch++;
	}
	putchar('\n');
	return (0);
}
