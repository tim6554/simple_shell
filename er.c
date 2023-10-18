#include "shell.h"

/**
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void _eputs(char *rst)
{
	int n = 0;

	if (!rst)
		return;
	while (rst[n] != '\0')
	{
		_eputchar(rst[n]);
		n++;
	}
}

/**
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char a)
{
	static int n;
	static char buf[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || n >= WRITE_BUF_SIZE)
	{
		write(2, buf, n);
		n = 0;
	}
	if (a != BUF_FLUSH)
		buf[n++] = a;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char b, int d)
{
	static int n;
	static char buf[WRITE_BUF_SIZE];

	if (b == BUF_FLUSH || n >= WRITE_BUF_SIZE)
	{
		write(d, buf, n);
		n = 0;
	}
	if (b != BUF_FLUSH)
		buf[n++] = b;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putsfd(char *rst, int d)
{
	int n = 0;

	if (!rst)
		return (0);
	while (*rst)
	{
		n += _putd(*rst++, d);
	}
	return (n);
}
