#include "shell.h"
/**
 * _strncpy - copy n char
 * @fin: string argument
 * @men: string argument for src
 * @i: integer argument
 * Return: fin
 */
char *_strncpy(char *fin, char *men, int i)
{
	int b;

	for (b = 0; i < i && men[b] != '\0'; b++)
	{
		fin[b] = men[b];
	}
	for (; b < i; b++)
	{
		fin[b] = '\0';
	}
	return (fin);
}
