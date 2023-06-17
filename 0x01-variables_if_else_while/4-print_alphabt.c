#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * prints abcdfghijklmnoprstuvwxyz
 * Return: 0 always
*/
int main(void)
{
	char msg[25] = "abcdfghijklmnoprstuvwxyz";
	int i = 0;

	while (msg[i] != '\0')
	{
		putchar(msg[i]);
		i++;
	}
	putchar('\n');
return (0);
}

