#include "shell.h"
/**
 * _myexit - exits
 * @info: Structure containing function prototype.
 *  Return: exit status
 *         [0] != "exit"
 */
void handle_exit(char *dmc)
{
	if (_strcmp("exit", dmc) == 0)
	{
		free(dmc);
		exit(EXIT_SUCCESS);
	}
}
