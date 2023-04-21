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
void exec_command(char *input, char *argv[], char **envp);
int handleothercommands(char **input_toks, char **envp);
void handlechdir(char **input_toks, char **envp);
void changedir(char *path, int cd_result);

void handle_env(char **input_toks);
void handle_setenv(char **input_toks);
void handle_unsetenv(char **input_toks);
void handle_echo(char **args, char **envp);
char *handle_comments(char *command);

void itoa(int n, char str[], int base);
void rev_string(char str[]);
int _atoi(char *str);
void exec_single_command(char *args[], char **argv,char **envp);
int get_exit_status(char **args);

#endif