# Custom Shell - myshellk

## What is the Shell?

The shell is a program that facilitates interaction with the operating system by accepting commands from the user through the terminal. It acts as an interface, forwarding user inputs to the operating system for execution.

## About this Project

This project represents a custom shell, named simple_shell, developed for Holberton School as part of the "Low-level programming & Algorithm - Linux and Unix system programming" curriculum. Implemented in the C programming language, this shell introduces additional functionalities beyond a standard shell.

### Essential Functionalities of simple_shell:

- Displays a custom prompt "#Kiro$ " when in interactive mode.
- Supports executing commands with arguments and handling absolute paths.
- Handles built-in commands such as "exit" and "env."
- Provides dynamic path resolution using the PATH environment variable.
- Manages signals such as Ctrl + C gracefully, preventing accidental shell termination.

### Files Description

- **command_exe.c:**
  - `printerror`: Prints an error message when a command is not found.
  - `execute_com`: Forks a new process to execute a command using `execve`.
  - `ex_com`: Determines the path and returns the exit status of a command.

- **get_path_env.c:**
  - `find_env_key`: Finds the value of an environment variable based on the key.
  - `_getenv`: Gets the value of an environment variable using the key.
  - `is_absolute_path`: Checks if a command is an absolute path.
  - `search_in_path`: Searches for a command in the directories specified by the PATH variable.
  - `_getpath`: Determines the path of a command, considering both absolute and relative paths.

- **king.c:**
  - `main`: The main function serving as the entry point for the custom shell.
  - `read_com`: Reads the user input for a command line.
  - `print_env`: Prints environment variables.
  - `_putchar`: Writes a string to standard output.

- **simple_shell.h:**
  - Header file containing function prototypes and necessary includes.

- **read_b_env.c:**
  - `read_com`: Reads the user input for a command line.
  - `print_env`: Prints environment variables.
  - `_putchar`: Writes a string to standard output.

- **strings_3.c:**
  - `_strdup`: Duplicates a string.
  - `_strcmp`: Compares two strings.
  - `_strlen`: Returns the length of a string.
  - `_strcat`: Concatenates two strings.
  - `_strcpy`: Copies a string.

- **tools_3.c:**
  - `reverse_str`: Reverses a string.
  - `_itoa`: Converts an integer to a string.
  - `freearray`: Frees a dynamically allocated array of strings.
  - `get_com_path`: Gets the path of the input command.

### List of Allowed Functions and System Calls for this Project

## List of Allowed Functions and System Calls

The development of this custom shell adheres to the following list of allowed functions and system calls:

- **File System Manipulation:**
  - [`access`](http://man7.org/linux/man-pages/man2/access.2.html) (man 2 access)
  - [`chdir`](http://man7.org/linux/man-pages/man2/chdir.2.html) (man 2 chdir)
  - [`close`](http://man7.org/linux/man-pages/man2/close.2.html) (man 2 close)
  - [`closedir`](http://man7.org/linux/man-pages/man3/closedir.3.html) (man 3 closedir)

- **Process Execution:**
  - [`execve`](http://man7.org/linux/man-pages/man2/execve.2.html) (man 2 execve)
  - [`exit`](http://man7.org/linux/man-pages/man3/exit.3.html) (man 3 exit)
  - [`_exit`](http://man7.org/linux/man-pages/man2/_exit.2.html) (man 2 _exit)
  - [`fork`](http://man7.org/linux/man-pages/man2/fork.2.html) (man 2 fork)

- **Input/Output:**
  - [`fflush`](http://man7.org/linux/man-pages/man3/fflush.3.html) (man 3 fflush)
  - [`read`](http://man7.org/linux/man-pages/man2/read.2.html) (man 2 read)
  - [`write`](http://man7.org/linux/man-pages/man2/write.2.html) (man 2 write)

- **Memory Management:**
  - [`malloc`](http://man7.org/linux/man-pages/man3/malloc.3.html) (man 3 malloc)
  - [`free`](http://man7.org/linux/man-pages/man3/free.3.html) (man 3 free)

- **Directory Handling:**
  - [`opendir`](http://man7.org/linux/man-pages/man3/opendir.3.html) (man 3 opendir)
  - [`readdir`](http://man7.org/linux/man-pages/man3/readdir.3.html) (man 3 readdir)
  - [`closedir`](http://man7.org/linux/man-pages/man3/closedir.3.html) (man 3 closedir)

- **Signal Handling:**
  - [`signal`](http://man7.org/linux/man-pages/man2/signal.2.html) (man 2 signal)
  - [`kill`](http://man7.org/linux/man-pages/man2/kill.2.html) (man 2 kill)

- **Process Termination:**
  - [`wait`](http://man7.org/linux/man-pages/man2/wait.2.html) (man 2 wait)
  - [`waitpid`](http://man7.org/linux/man-pages/man2/waitpid.2.html) (man 2 waitpid)
  - [`wait3`](http://man7.org/linux/man-pages/man2/wait3.2.html) (man 2 wait3)
  - [`wait4`](http://man7.org/linux/man-pages/man2/wait4.2.html) (man 2 wait4)

- **File Operations:**
  - [`open`](http://man7.org/linux/man-pages/man2/open.2.html) (man 2 open)
  - [`stat`](http://man7.org/linux/man-pages/man2/stat.2.html) (__xstat) (man 2 stat)
  - [`lstat`](http://man7.org/linux/man-pages/man2/lstat.2.html) (__lxstat) (man 2 lstat)
  - [`fstat`](http://man7.org/linux/man-pages/man2/fstat.2.html) (__fxstat) (man 2 fstat)

- **String Manipulation:**
  - [`strtok`](http://man7.org/linux/man-pages/man3/strtok.3.html) (man 3 strtok)

- **Miscellaneous:**
  - [`getcwd`](http://man7.org/linux/man-pages/man3/getcwd.3.html) (man 3 getcwd)
  - [`isatty`](http://man7.org/linux/man-pages/man3/isatty.3.html) (man 3 isatty)
  - [`perror`](http://man7.org/linux/man-pages/man3/perror.3.html) (man 3 perror)
  - (Feel free to add any additional functions or system calls as needed.)

For detailed information about each function or system call, refer to the provided man pages.


## Usage

To experience our custom shell, follow these steps:

1. Clone our repository using the command (ensure Git is installed):

```bash
git clone https://github.com/kirolloushany03/simple_shell
```

2. Change directory to simple_shell:

```bash
cd simple_shell
```

3. Compile the C files:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o myshellk
```

4. Run the shell:

```bash
./myshellk
```

## Exiting the Shell

When exiting the shell, use one of the following methods:

1. Type the command "exit":

```bash
exit
```

2. Press Ctrl + D.
