#include "shell.h"
/**
 * interactive - is interactive mode
 * @info: address
 *
 * Return: 1 if success, 0 otherwise
 */
char *_strcat(char *fin, char *men)
{
	int n = 0, d = 0, j;

	while (men[n] != '\0')
	{
		n++;
	}
	while (fin[d] != '\0')
	{
		d++;
	}
	for (j = 0; j < n; j++)
	{
		fin[d + j] = men[j];
	}
	fin[d + n] = '\0';
	return (fin);
}
