*This project was created as part of the 42 curriculum by foehler-.*
# Libft

A custom C library implementing standard C library functions and additional utility functions. This library will be continuously used in future projects.

## Description

Libft is a collection of commonly used C functions reimplemented from scratch. It includes standard library functions from `<string.h>`, `<stdlib.h>`, `<ctype.h>`, and additional utility functions for string manipulation, memory management, and linked list operations.

## Compilation

### Build the library
```bash
make
```

### Clean object files
```bash
make clean
```

### Remove all generated files
```bash
make fclean
```

### Rebuild everything
```bash
make re
```

## Usage

1. Compile the library:
```bash
make
```

2. Include the header in your C file:
```c
#include "libft.h"
```

3. Compile your program with the library:
```bash
cc -Wall -Wextra -Werror your_file.c -L. -lft
```

## Example

```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    char *str = ft_strdup("Hello, World!");
    char *upper = ft_strmapi(str, (char (*)(unsigned int, char))ft_toupper);
    
    ft_putendl_fd(upper, 1);
    
    free(str);
    free(upper);
    return (0);
}
```

## Project Structure

The library is organized into three main categories:

### Part 1 - Libc Functions
Standard C library functions reimplemented:
- **Character checks**: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- **String functions**: `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strlcpy`, `ft_strlcat`, `ft_strnstr`, `ft_strdup`
- **Memory functions**: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
- **Conversion functions**: `ft_atoi`, `ft_toupper`, `ft_tolower`

### Part 2 - Additional Functions
Extended string and memory manipulation functions:
- `ft_substr` - Extract substring from string
- `ft_strjoin` - Concatenate two strings
- `ft_strtrim` - Trim characters from both ends of string
- `ft_split` - Split string by delimiter
- `ft_itoa` - Convert integer to string
- `ft_strmapi` - Apply function to each character
- `ft_striteri` - Apply function to each character with index
- `ft_putchar_fd` - Output character to file descriptor
- `ft_putstr_fd` - Output string to file descriptor
- `ft_putendl_fd` - Output string with newline to file descriptor
- `ft_putnbr_fd` - Output integer to file descriptor

### Part 3 - Linked List Functions
Functions for manipulating linked lists:
- `ft_lstnew` - Create new list node
- `ft_lstadd_front` - Add node at beginning
- `ft_lstadd_back` - Add node at end
- `ft_lstsize` - Count number of nodes
- `ft_lstlast` - Get last node
- `ft_lstdelone` - Delete single node
- `ft_lstclear` - Delete all nodes
- `ft_lstiter` - Iterate and apply function
- `ft_lstmap` - Create new list by applying function

## Resources

* **UNIX Man Pages**: Primary reference for standard library functions.
* **C Reference Guide**: Used for syntax and language standard checks.
* **AI Assistance**: AI usage was strictly limited to specific concept clarifications, test case generation, and code verification. All AI outputs were thoroughly reviewed and validated under human control.

## Technical Details

- **Language**: C
- **Compiler**: cc (gcc/clang)
- **Flags**: `-Wall -Wextra -Werror`
- **Memory**: All dynamically allocated memory is properly managed

## Author

**foehler** - [@feli-ohl](https://github.com/feli-ohl)

## License

This project is part of the 42 School curriculum.
