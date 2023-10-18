#ifndef SHELL_H
#define SHELL_H
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_C 10
/**
 * struct denim - structure that contains vars
 * @cnt: lines cnt
 */
typedef struct denim
{
	int count;
} denim;
void prompt(char **var, char **envp, bool flg);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int n);
char *get_path(char *cmd);
char *_getenv(char *name);
char **tokenize_env(char *path);
extern char **environ;
void geterror(denim *n, char **var, char *dmc);
char *_strcat(char *dest, char *src);
char *handle_path(char **rgv, char *cmd);
char *_strcpy(char *fin, char *men);
int _strlen(char *s);
void handle_exit(char *dmc);
void runcmd(char **rgv, char **arv, char **envp);
char *trim(char *cmd);


#endif
