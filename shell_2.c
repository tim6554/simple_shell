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
	char *cmd = NULL, *rgv[MAX_C];
	int x;

	while (1)
	{
		if (flg && isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", _strlen("$ "));
		signal(SIGINT, sig_handler);
		num_c = getline(&cmd, &n, stdin);
		if (num_c == -1) /*handles the end file case*/
		{
			free(cmd);
			exit(EXIT_SUCCESS);
		}
		if (cmd[num_c - 1] == '\n')
			cmd[num_c - 1] = '\0';
		cmd = trim(cmd);
		if (_strlen(cmd) == 0)
			continue;
		x = 0;
		rgv[x] = strtok(cmd, " \n");
		handle_exit(cmd);
		handle_path(rgv, cmd);
		while (rgv[x])
		{
			x++;
			rgv[x] = strtok(NULL, " \n");
		}
		runcmd(rgv, var, envp); 
	}
	free(cmd);
}
