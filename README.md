# get_next_line
The get_next_line() function resembles the standard getline() function. It lets you read the text file pointed to by the file descriptor, one line at a time.

return value:

It returns the line that was read. If there is nothing else to read or if an error occurred, it should return NULL.
The returned line includes the terminating \n character, except if the end of file was reached and does not end with a \n character.

# 🛠️ Usage
Requirements

This program is written in C language for Linux distributions and thus needs the clang compiler and some standard C libraries to run.

Instructions

Compiling the program

$ make

Executing the program

$ ./gnl

📑 Index
@root

📁 inc: contains the program's headers.

📁 src: contains the source code of the program.

Makefile - contains instructions for compiling the program and testing it.
