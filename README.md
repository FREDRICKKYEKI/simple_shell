#A Simple shell
This is a simple UNIX command interpreter based on bash and Sh, as a course work project during the **ALX** Software Engineering program.

## Overview

This is a command language interpreter that executes commands read from the standard input or from a file, authored by **Fredrick Kyeki** and **Lennox Namasaka**
### Invocation

Usage: **flexsh** 
Sodash is started with the standard input connected to the terminal. To start, compile all .c located in this repository by using this command: 
```
gcc -Wall -Werror -Wextra -pedantic *.c -o flexsh
./flexsh
```


**flexsh** is allowed to be invoked interactively and non-interactively. If **flexsh** is invoked with standard input not connected to a terminal, it reads and executes received commands in order.

Example:
```
$ echo "echo 'holberton'" | ./flexsh
'holberton'
$
```

When **flexsh** is invoked with standard input connected to a terminal (determined by isatty(3), the interactive mode is opened. **flexsh** Will be using the following prompt `^-^ `.

Example:
```
$./flexsh
$
```

If a command line argument is invoked, **flexsh** will take that first argument as a file from which to read commands.

Example:
```
$ cat text
echo 'holberton'
$ ./flexsh text
'holberton'
$
```