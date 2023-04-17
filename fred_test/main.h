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
void handleothercommands(char **input_toks, char **envp);
void handlechdir(char **input_toks, char **envp);

#endif