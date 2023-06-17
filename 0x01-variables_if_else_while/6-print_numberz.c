#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * prints 0123456789 using only putchar
 * Return: 0 Always
 */
int main(void)
{
	int i = 0;

	while (i < 10)
	{
		putchar(48 + i);
		i++;
	}
	putchar('\n');
return (0);
}
