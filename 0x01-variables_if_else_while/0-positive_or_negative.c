#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - A program checks if the random number n is positiv or negative
 * Return: 0 always
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	if (n > 0)
		printf("%d is positive\n", n);
	else if (n == 0)
		printf("%d is zero\n", n);
	else
		printf("%d is negative\n", n);
	return (0);
}
