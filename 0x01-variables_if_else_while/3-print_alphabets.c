#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * prints the alphabet in lowercase then uppercase
 * Return: 0 Always
 */
int main(void)
{
	char alphabet1[27] = "abcdefghijklmnopqrstuvwxyz";
	char alphabet2[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i = 0;

	while (alphabet1[i] != '\0')
	{
		putchar(alphabet1[i]);
		i++;
	}
	i = 0;
	while (alphabet2[i] != '\0')
	{
		putchar(alphabet2[i]);
		i++;
	}
	putchar('\n');
return (0);
}
