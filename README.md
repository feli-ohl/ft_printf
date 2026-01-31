*This project was created as part of the 42 curriculum by foehler-.*
# ft_printf

![Language](https://img.shields.io/badge/language-C-blue.svg)
![Standard](https://img.shields.io/badge/standard-C99-green.svg)
![License](https://img.shields.io/badge/license-MIT-orange.svg)

## Description

**ft_printf** is a custom implementation of the standard C library function `printf`. This project mimics the behavior of the original function, allowing for formatted output handling.

The goal of this project is to learn about variadic functions (`stdarg.h`) and to deepen understanding of formatting and string manipulation in C.

## Features

This implementation supports the following conversions:

| Specifier | Description |
| :---: | :--- |
| `%c` | Prints a single character. |
| `%s` | Prints a string (as defined by the common C convention). |
| `%p` | The `void *` pointer argument has to be printed in hexadecimal format. |
| `%d` | Prints a decimal (base 10) number. |
| `%i` | Prints an integer in base 10. |
| `%u` | Prints an unsigned decimal (base 10) number. |
| `%x` | Prints a number in hexadecimal (base 16) lowercase format. |
| `%X` | Prints a number in hexadecimal (base 16) uppercase format. |
| `%%` | Prints a percent sign. |

### Supported Flags (bonus)

| Flag | Description |
| :---: | :--- |
| `#` | Used with `x` or `X` specifiers the value is preceeded with `0x` or `0X` respectively, for values different than zero. |
| `+` | Forces to preceed the result with a plus or minus sign (`+` or `-`) even for positive numbers. |
| ` ` | (Space) If no sign is going to be written, a blank space is inserted before the value. |

## Installation & Compilation

### Requirements

- GCC or Clang compiler
- Make

### Building the Library

Clone the repository and compile the library using the Makefile:

```bash
git clone <repository-url> ft_printf
cd ft_printf
make
```

This will generate a `libftprintf.a` static library file.

### Makefile Rules

- `make`: Compiles the library `libftprintf.a`.
- `make clean`: Removes object files.
- `make fclean`: Removes object files and the library.
- `make re`: Recompiles everything from scratch.

## Usage

To use **ft_printf** in your project, include the header file and link against the library.

### 1. Include the Header

```c
#include "ft_printf.h"
```

### 2. Compile with the Library

When compiling your project, link it with `libftprintf.a`. You likely need to tell the compiler where to find it.

```bash
cc main.c -L. -lftprintf -o my_program
```

*(Assuming `libftprintf.a` is in the current directory)*

### Example Code

```c
#include "ft_printf.h"

int main(void)
{
    char *str = "World";
    int num = 42;
    void *ptr = &num;

    ft_printf("Hello, %s!\n", str);
    ft_printf("The answer is %d\n", num);
    ft_printf("Pointer address: %p\n", ptr);
    ft_printf("Hexadecimal: %x\n", 255);
    
    return (0);
}
```

## Resources

* **UNIX Man Pages**: Primary reference for standard library functions.
* **C Reference Guide**: Used for syntax and language standard checks.
* **AI Assistance**: AI usage was strictly limited to specific concept clarifications, test case generation, and code verification. All AI outputs were thoroughly reviewed and validated under human control.

## Author

**foehler** - [@feli-ohl](https://github.com/feli-ohl)
