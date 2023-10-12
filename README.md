# get_next_line
The get_next_line() function resembles the standard getline() function. It lets you read the text file pointed to by the file descriptor, one line at a time.

### return value:
It returns the line that was read. If there is nothing else to read or if an error occurred, it should return NULL.

The returned line includes the terminating \n character, except if the end of file was reached and does not end with a \n character.

### how to use:
clang -Wall -wextra -Werror get_next_line.c get_next_line_utils.c get_next_line.h main.c
