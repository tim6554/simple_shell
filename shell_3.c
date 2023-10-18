#include "shell.h"
/**
 * _myhistory - history list, one starting at 0.
 * @info: Struct containing arg. 
 *  Return: Always 0
 */
char *handle_path(char **rgv, char *dmc)
{
	char *p;

	p = malloc(_strlen("/bin/") + _strlen(dmc) + 1);
	if (!p)
	{
		return (NULL);
	}
	_strcpy(p, "/bin/");

	if (dmc[0] != '/' && dmc[0] != '.')
	{
		rgv[0] = _strcat(p, dmc);
		return (rgv[0]);
	}
	free(p);
	return (dmc);
}
