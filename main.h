#ifndef MAIN_H
#define MAIN_H

#define EXIT WIFEXITED
#define STATUS WEXITSTATUS

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>


/* function prototypes */
char *_getline(void);
void handle_exit(char **command, char *input, int _exit);
void handle_env(char **env);
char **get_token(char *input);

char *get_path(char **env);
int handle_path(char **command, char **env);
int execute(char **command, char **av, char **env, char *input, int path_ret,
	    int process_num);

int handle_other(char **command, char *user_input, int exit_status,
		 char **env, char *av);
void handle_echo(char **command, int exit_status, char **env);
void change_dir(char **command, char *av);
void handle_replacement(char **command, int exit_status);

void handle_setenv(char **input_toks);
void handle_unsetenv(char **input_toks);

/* string functions */
int _strcmp(char *s1, char *s2);
char *_strtok(char *str, const char *delim);
int _strlen(char *str);
size_t _strncmp(char *s1, char *s2, size_t n);

char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
void _itoa(int n, char *str, int base);

void rev_string(char *str);
char *_strdup(const char *str);

/* print functions */
int _putchar(char c);
int _puts(char *str);
void print_err(char *name, int process_num, char *command);

#endif
