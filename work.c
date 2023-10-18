#include "shell.h"
/**
 * _strcmp - unction
 * @a1: first function
 * @a2: second function
 * Return: p
 */
int _strcmp(char *a1, char *a2)
{
	int p = 0;

	while (*a1 == *a2 && *a1 != '\0')
	{
		a1++;
		a2++;
	}
	if (a1 != a2)
		p = *a1 - *a2;

	return (p);
}
