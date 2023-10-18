#include "shell.h"
/**
 * interactive - is interactive mode
 * @info: address
 *
 * Return: 1 if success, 0 otherwise
 */
char *trim(char *dmc)
{
	char *cdmc;
	int n = 0, len;

	while (dmc[n] == ' ')
		n++;
	len = _strlen(dmc) - n + 1;
	cdmc = malloc(len + 1);
	if (!cdmc)
	{
		perror("Allocation Failed\n");
		return (NULL);
	}
	_strncpy(cdmc, dmc + n, len);
	cpcmd[len] = '\0';
	_strcpy(dmc, cdmc);
	free(cdmc);
	return (dmc);
}
