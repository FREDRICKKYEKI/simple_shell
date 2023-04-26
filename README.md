#A Simple shell
This is a simple UNIX command interpreter based on bash and Sh, as a course work project during the **ALX** Software Engineering program.

## Overview

This is a command language interpreter that executes commands read from the standard input or from a file, authored by **[Fredrick Kyeki](https://github.com/fredrickkyeki)** and **[Lennox Namasaka](https://github.com/NamasakaLennox).**
### Invocation

Usage: **./hsh**
hsh is started with the standard input connected to the terminal. To start, compile all .c located in this repository by using this command: 
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
./hsh
```


**hsh** is allowed to be invoked interactively and non-interactively. If **hsh** is invoked with standard input not connected to a terminal, it reads and executes received commands in order.

Example:
```
$ echo "echo 'alx'" | ./hsh
'alx'
$
```

When **hsh** is invoked with standard input connected to a terminal (determined by isatty(3), the interactive mode is opened. **hsh** Will be using the following prompt `^-^ `.

Example:
```
$./hsh
$
```

If a command line argument is invoked, **hsh** will take that first argument as a file from which to read commands.

Example:
```
$ cat text
echo 'alx'
$ ./hsh text
'alx'
$
```

## Authors & Copyrights

* Fredrick Kyeki <[fredrickkyeki](https://github.com/fredrickkyeki)>
* Lennox Namasaka <[NamasakaLennox](https://github.com/NamasakaLennox)>

## More information

**hsh** is a simple shell unix command interpreter that is part of the ALX low level programming module at ALX School and is intended to emulate the basics **sh** shell.
