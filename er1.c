#include "shell.h"

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
int _erratoi(char *a)
{
	int n = 0;
	unsigned long int result = 0;

	if (*a == '+')
		a++;
	for (n = 0;  a[n] != '\0'; n++)
	{
		if (a[n] >= '0' && a[n] <= '9')
		{
			result *= 10;
			result += (a[n] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *info, char *erst)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(erst);
}

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
int print_d(int u, int d)
{
	int (*__putchar)(char) = _putchar;
	int n, count = 0;
	unsigned int _abs_, current;

	if (d == STDERR_FILENO)
		__putchar = _eputchar;
	if (u < 0)
	{
		_abs_ = -u;
		__putchar('-');
		count++;
	}
	else
		_abs_ = u;
	current = _abs_;
	for (n = 1000000000; n > 1; n /= 10)
	{
		if (_abs_ / n)
		{
			__putchar('0' + current / n);
			count++;
		}
		current %= n;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void remove_comments(char *f)
{
	int n;

	for (n = 0; f[n] != '\0'; n++)
		if (f[n] == '#' && (!n || f[n - 1] == ' '))
		{
			f[n] = '\0';
			break;
		}
}
