#include "shell.h"
/**
 * interactive - is interactive mode
 * @info: address
 *
 * Return: 1 if success, 0 otherwise
 */
int main(int car, char **var, char **envp)
{
	bool interactive = (car == 1 && isatty(STDIN_FILENO));

	prompt(var, envp, interactive);
	return (0);
}
