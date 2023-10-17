#ifndef _SHELL.H_
#define _SHELL.H_
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
extern char **environ;
int charput(char c);
void place(char *str);
char *str_concat(char *s1, char *s2);
int slash(char *dmc);
int compExit(char *a1, char *a2);
int compEnv(char *a1, char *a2);
void execute_proc(char **cmd);
char **id_str(char *par);
void cnt(int giz);
void place(char *str);
char *findfile(char *command);
char *find_command(char *command);
int compare(char *s1, char *s2);
int _strcmpdir(char *s1, char *s2);
char *show_input(void);
void prompt(void);
char *_strcat(char *src);
int _strlen(char *str);
#endif
