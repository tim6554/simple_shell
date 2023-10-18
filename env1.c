#include "shell.h"
/**
 *_atoi - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in the string, converted number otherwise
 */

int _strncmp(char *s1, char *s2, int a)
{
	if (!a)
		return (0);
	if (*s1 == *s2)
		return (*s1 ? _strncmp(s1 + 1, s2 + 1, a - 1) : 0);
	if (*s1)
		return (1);
	if (*s2)
		return (-1);
	return (*s1 - *s2);
}
