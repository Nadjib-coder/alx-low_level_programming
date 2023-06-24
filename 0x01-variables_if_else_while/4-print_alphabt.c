#include <stdio.h>
#include <stdlib.h>

/**
 * main - A program that prints the alphabet in lowercase
 * all the letters except q and e
 * Return: 0 (Success)
 */
int main(void)
{
        char ch;

        for (ch = 'a'; ch <= 'z'; ch++)
        {
                if (ch != 'q' && ch != 'e')
                {
                        putchar(ch);
                }
        }
        putchar('\n');
        return (0);
}

