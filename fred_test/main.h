#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

char *getenvp(char *var_name, char **envp);
char *getexecpath(char *name, char *dirs);
void changedir(char *path, int cd_result);

void handlechdir(char **input_toks, char **envp);
void handle_env(char **input_toks);
void handle_setenv(char **input_toks);
void handle_unsetenv(char **input_toks);
void handle_echo(char **args, char **envp);
char *handle_comments(char *command);
int handleothercommands(char **input_toks, char **envp);

/*string functions*/
void itoa(int n, char str[], int base);
void rev_string(char str[]);
int _atoi(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *str);
size_t _strncmp(char *s1, char *s2, size_t n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
char *_strdup(const char *str);

void exec_command(char *input, char *argv[], char **envp, int *exit_status);
void exec_single_command(char *args[], char **argv,char **envp, int *exit_status);
int get_exit_status(char **args);

int _putchar(char c);
int _puts(char *str);

#endif
