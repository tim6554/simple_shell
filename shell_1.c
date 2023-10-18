#include "shell.h"


/**
 * is_delim - checks if delimeter
 * @b: to check
 * @dlm: the delimeter str
 * Return: 1 if true, 0 if false
 */
int is_delim(char b, char *dlm)
{
	while (*dlm)
		if (*dlm++ == b)
			return (1);
	return (0);
}

/**
 * interactive - is interactive mode
 * @info: address
 *
 * Return: 1 if success, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}


/**
 *_atoi - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int n, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (n = 0;  s[n] != '\0' && flag != 2; n++)
	{
		if (s[n] == '-')
			sign *= -1;

		if (s[n] >= '0' && s[n] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[n] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

/**
 *_isalpha - checks for alphabetic character
 *@s: input
 *Return: 1 if aplha, 0 otherwise
 */

int _isalpha(int s)
{
	if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
		return (1);
	else
		return (0);
}
