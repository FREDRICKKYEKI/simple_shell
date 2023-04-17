#ifndef MAIN_H
#define MAIN_H

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

/* string manupulation */
int _strcmp(char *s1, char *s2);
char *_strtok(char *str, const char *delim);

/* print functions */
int _putchar(char c);
int _puts(char *str);

#endif
