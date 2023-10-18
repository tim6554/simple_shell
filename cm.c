#include "shell.h"
/**
 * is_delim - checks if delimeter
 * @b: to check
 * @dlm: the delimeter str
 * Return: 1 if true, 0 if false
 */
void runcmd(char **arv, char **rgv, char **envp)
{
	pid_t child;
	int s;


	child = fork();

	if (child == -1)
	{
		perror("Process Error");
		exit(EXIT_FAILURE);
	}
	if (child == 0)
	{

		if (execve(rgv[0], rgv, envp) == (-1))
		{
			write(STDOUT_FILENO, arv[0], _strlen(arv[0]));
			write(STDOUT_FILENO, ": No such file or directory",
			_strlen(": No such file or directory"));
			write(STDOUT_FILENO, "\n", 1);
			
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&s);
	}
}
