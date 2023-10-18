#include "shell.h"
/**
 * _strlen - length of a string
 * @a: string
 * Return: len
 */
int _strlen(char *a)
{
	int b = 0;

	while (*(a + b) != '\0')
	{
		b++;
	}
	return (b);
}
