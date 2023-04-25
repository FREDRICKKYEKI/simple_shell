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

/* function prototypes */
char *_getline(void);
void handle_exit(char **command, char *input, int _exit);
void handle_env(char **env);
char **get_token(char *input);
char *get_path(char **env);
int handle_path(char **command, char **env);
int execute(char **command, char **av, char **env, char *input, int path_ret);
int handle_other(char **command, char *user_input, int exit_status,
                 char **env);
void handle_echo(char **command, int exit_status, char **env);

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

/* print functions */
int _putchar(char c);
int _puts(char *str);

#endif
