#include "shell.h"

/**
 * slash - identify char.
 * @dmc: string
 * Return: 1 if yes 0 if no.
 */
int slash(char *dmc)
{
  int i = 0;

  while (dmc[cont])
    {
      if (dmc[0] == '/')
	{
	  printf("%c\n", dmc[0]);
	  return (1);
	}

      i++;
    }
  return (0);
}

/**
 * compExit - identify 1st char is a slash.
 * @a1: 1st str
 * @a2: exit str
 * Return: 1 if yes 0 if no.
 */
int compExit(char *a1, char *a2)
{
  int n = 0;

  for (; (*a2 != '\0' && *a1 != '\0') && *a1 == *a2; a1++)
    {
      if (n == 3)
	break;
      n++;
      a2++;
    }

  return (*a1 - *a2);
}

/**
 * compEnv - identify 1st char is a slash.
 * @a1: 1st str
 * @a2: exit str
 * Return: 1 if yes 0 if no.
 */
int compEnv(char *a1, char *a2)
{
  int n = 0;

  for (; (*a2 != '\0' && *a1 != '\0') && *a1 == *a2; a1++)
    {
      if (n == 2)
	break;
      n++;
      a2++;
    }

  return (*a1 - *a2);
}
/**
 * id_str - identyfy input.
 * @par: call prompt from another function (prompt)
 * Return: str
 **/
char **id_str(char *par)
{
  char **pls = malloc(1024 * sizeof(char *));
  char *slt;
  int n = 0;
  char *dlm = " \t\n";


  slt = strtok(par, dlm);

  while (slt != NULL)
    {
      pls[n] = slt;
      n++;
      slt = strtok(NULL, dlm);
    }
  execute_proc(pls);
  return (pls);

}
/**
 * cnt - dont leave the shell
 * @giz: keep going shell
 **/
void  cnt(int giz)
{
  (void) giz;
  write(1, "\n$ ", 3);
}
