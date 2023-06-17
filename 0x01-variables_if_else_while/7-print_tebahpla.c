#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 *
 * prints the alphabet in revrse
 * Return: 0 Always
 */
int main(void)
{
	char msg[27] = "zyxwvutsrqponmlkjihgfedcba";
	int i = 0;

	while (msg[i] != '\0')
	{
		putchar(msg[i]);
		i++;
	}
	putchar('\n');
return (0);
}
