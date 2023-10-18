#include "shell.h"


/**
 * _myhelp - directory of the process
 * @info: Structure constant function prototype.
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **argy;

	argy = info->argv;
	_puts("call for help works but not yet shown \n");
	if (0)
		_puts(*argy); 
	return (0);
}


/**
 * _myexit - exits
 * @info: Structure containing function prototype.
 *  Return: exit status
 *         [0] != "exit"
 */
int _myexit(info_t *info)
{
	int ec;

	if (info->argv[1]) 
		ec = _erratoi(info->argv[1]);
		if (ec == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes directory 
 * @info: Structure containing function prototype.
 *  Return: Always 0
 */
int _mycd(info_t *info)
{
	char *a, *wd, buffer[1024];
	int chwd_ret;

	a = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		wd = _getenv(info, "HOME=");
		if (!wd)
			chwd_ret = 
				chwd((wd = _getenv(info, "PWD=")) ? wd : "/");
		else
			chwd_ret = chwd(wd);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(a);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chwd_ret = 
			chwd((wd = _getenv(info, "OLDPWD=")) ? wd : "/");
	}
	else
		chwd_ret = chwd(info->argv[1]);
	if (chwd_ret == -1)
	{
		print_error(info, "can not change dir to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
