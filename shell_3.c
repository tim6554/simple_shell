#include "shell.h"


/**
 * unset_str - sets string to value
 * @info: par struct
 * @rst: str alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_str(info_t *info, char *rst)
{
	char *a, b;
	int ter;

	a = _strchr(rst, '=');
	if (!a)
		return (1);
	b = *a;
	*a = 0;
	ter = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, rst, -1)));
	*a = b;
	return (ter);
}


/**
 * _myhistory - history list, one starting at 0.
 * @info: Struct containing arg. 
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * set_alias - give alias to string value
 * @info: par struct
 * @rst: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *rst)
{
	char *s;

	s = _strchr(rst, '=');
	if (!s)
		return (1);
	if (!*++s)
		return (unset_str(info, rst));

	unset_str(info, rst);
	return (add_node_end(&(info->alias), rst, 0) == NULL);
}

/**
 * print_ppl - prints an alias string
 * @nd: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_ppl(list_t *nd)
{
	char *s = NULL, *t = NULL;

	if (nd)
	{
		s = _strchr(node->rst, '=');
		for (t = node->str; t <= s; t++)
			_putchar(*t);
		_putchar('\'');
		_puts(s + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - copies alias builtin 
 * @info: Structure containing potential arguments.
 */
int _myalias(info_t *info)
{
	int b = 0;
	char *s = NULL;
	list_t *nd = NULL;

	if (info->argc == 1)
	{
		nd = info->alias;
		while (nd)
		{
			print_alias(nd);
			nd = nd->next;
		}
		return (0);
	}
	for (b = 1; info->argv[b]; b++)
	{
		s = _strchr(info->argv[b], '=');
		if (s)
			set_alias(info, info->argv[b]);
		else
			print_alias(node_starts_with(info->alias, info->argv[b], '='));
	}

	return (0);
}
