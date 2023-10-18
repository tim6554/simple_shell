#include "shell.h"
/**
 * _mycd - changes directory 
 * @info: Structure containing function prototype.
 *  Return: Always 0
 */
void sig_handler(int i)
{
	(void)i;
	write(STDOUT_FILENO, "\n$ ", _strlen("\n$ "));
}
/**
 * _mycd - changes directory 
 * @info: Structure containing function prototype.
 *  Return: Always 0
 */
void prompt(char **var, char **envp, bool flg)
{
	size_t n = 0;
	ssize_t num_c = 0;
	char *dmc = NULL, *rgv[MAX_C];
	int x;

	while (1)
	{
		if (flg && isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", _strlen("$ "));
		signal(SIGINT, sig_handler);
		num_c = getline(&dmc, &n, stdin);
		if (num_c == -1) 
		{
			free(dmc);
			exit(EXIT_SUCCESS);
		}
		if (dmc[num_c - 1] == '\n')
			dmc[num_c - 1] = '\0';
		dmc = trim(dmc);
		if (_strlen(dmc) == 0)
			continue;
		x = 0;
		rgv[x] = strtok(dmc, " \n");
		handle_exit(dmc);
		handle_path(rgv, dmc);
		while (rgv[x])
		{
			x++;
			rgv[x] = strtok(NULL, " \n");
		}
		runcmd(rgv, var, envp); 
	}
	free(dmc);
}
