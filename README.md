#A Simple shell
This is a simple UNIX command interpreter based on bash and Sh, as a course work project during the **ALX** Software Engineering program.

## Overview

This is a command language interpreter that executes commands read from the standard input or from a file, authored by **[Fredrick Kyeki](https://github.com/fredrickkyeki)** and **[Lennox Namasaka](https://github.com/lennoxnamasaka).**
### Invocation

Usage: **./flexsh** 
flexsh is started with the standard input connected to the terminal. To start, compile all .c located in this repository by using this command: 
```
gcc -Wall -Werror -Wextra -pedantic *.c -o flexsh
./flexsh
```


**flexsh** is allowed to be invoked interactively and non-interactively. If **flexsh** is invoked with standard input not connected to a terminal, it reads and executes received commands in order.

Example:
```
$ echo "echo 'alx'" | ./flexsh
'alx'
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
echo 'alx'
$ ./flexsh text
'alx'
$
```

## Authors & Copyrights

* Fredrick Kyeki <[fredrickkyeki](https://github.com/fredrickkyeki)>
* Lennox Namasaka <[lennoxnamasaka](https://github.com/lennoxnamasaka)>

## More information

**flexsh** is a simple shell unix command interpreter that is part of the ALX low level programming module at ALX School and is intended to emulate the basics **sh** shell.

