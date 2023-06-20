#include "main.h"

/**
 * main - a program that write _putchar
 * Return: Always 0
 */
int main(void)
{
	char txt[] = "_putchar";
	int i;

	for (i = 0; txt[i] != '\0'; i++)
	{
		_putchar(txt[i]);
	}
	_putchar('\n');
	return (0);
}

