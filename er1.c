#include "shell.h"
/**
 * _myhelp - directory of the process
 * @info: Structure constant function prototype.
 *  Return: Always 0
 */
int intlen(int i)
{
	unsigned int num;
	int nel = 1;

	if (i < 0)
	{
		nel++;
		num = i * -1;
	}
	else
	{
		num = i;
	}
	while (num > 9)
	{
		nel++;
		num = num / 10;
	}

	return (nel);
}
/**
 * _myhelp - directory of the process
 * @info: Structure constant function prototype.
 *  Return: Always 0
 */
char *_itoa(int num)
{
	char *f;
	size_t  a;
	int nel = intlen(num);

	buff = malloc(nel + 1);
	if (!f)
	{
		return (NULL);
	}
	f[nel] = '\0';
	if (num < 0)
	{
		a = num * -1;
		*f = '-';
	}
	else
		a = num;
	nel--;

	do {
		*(f + nel) = (a % 10) + '0';
		a /= 10;
		nel--;
	} while (a > 0);
		return (f);
}
/**
 * _myhelp - directory of the process
 * @info: Structure constant function prototype.
 *  Return: Always 0
 */
void geterror(denim *n, char **var, char *dmc)
{
	int len;
	char *emsg, *v_string;

	v_string = _itoa(n->cnt);
	len = _strlen(var[0]) + _strlen(dmc) + _strlen(v_string) + 17;
	emsg = malloc(len);
	if (!errmsg)
	{
		return;
	}
	_strcpy(emsg, var[0]);
	_strcat(emsg, ": ");
	_strcat(emsg, v_string);
	_strcat(emsg, ": ");
	_strcat(emsg, dmc);
	_strcat(emsg, ": not found\n");
	_strcat(emsg, "\0");
	write(STDOUT_FILENO, emsg, len);
	free(emsg);
}
