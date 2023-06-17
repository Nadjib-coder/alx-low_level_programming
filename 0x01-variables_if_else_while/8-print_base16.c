#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 *
 * prints the base 16
 * 0123456789abcdef
 * Return: 0 Always
 */
int main(void)
{
	char msg[17] = "0123456789abcdef";
	int i = 0;

	while (msg[i] != '\0')
	{
		putchar(msg[i]);
		i++;
	}
	putchar('\n');
return (0);
}
