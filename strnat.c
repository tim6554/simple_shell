#include "shell.h"
/**
 * _strncat - Concantenates
 * @fin: Pointer to destination string.
 * @men: Pointer to source string.
 * @b: b bytes to copy from src.
 * Return: Pointer to destination string.
 */
char *_strncat(char *fin, const char *men, size_t b)
{
	size_t fin_len = _strlen(fin);
	size_t i;

	for (i = 0; i < b && men[i] != '\0'; i++)
		fin[fin_len + i] = men[i];
	fin[fin_len + i] = '\0';

	return (fin);
}
