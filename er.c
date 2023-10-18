#include "shell.h"
/**
 *_isalpha - checks for alphabetic character
 *@s: input
 *Return: 1 if aplha, 0 otherwise
 */
char *_strcpy(char *fin, char *men)
{
	int n, cnt = 0;

	while (men[cnt] != '\0')
	{
		cnt++;
	}
	for (i = 0; n < cnt; n++)
	{
		fin[n] = men[n];
	}
	fin[n] = '\0';
	return (fin);
}
