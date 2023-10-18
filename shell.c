#include "shell.h"
/**
 * interactive - is interactive mode
 * @info: address
 *
 * Return: 1 if success, 0 otherwise
 */
int main(int arc, char **arv, char **envp)
{
	bool interactive = (arc == 1 && isatty(STDIN_FILENO));

	prompt(arv, envp, interactive);
	return (0);
}
