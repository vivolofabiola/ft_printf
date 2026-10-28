*This project has been created as part of the 42 curriculum by fvivolo.*

# ft_printf

## Description

`ft_printf` is a re-implementation of a part of the C standard `printf` function. It builds a static library, `libftprintf.a`, that prints formatted text to the standard output and returns the number of characters written.

The goal of the project is to learn how variadic functions work in C (`va_list`, `va_start`, `va_arg`, `va_end`), and how to structure a program so that every conversion is handled by a small, separate function.

### Supported conversions

| Conversion | Output |
|---|---|
| `%c` | a single character |
| `%s` | a string (`(null)` if the pointer is `NULL`) |
| `%p` | a pointer address in hexadecimal, prefixed with `0x` (`(nil)` for `NULL`) |
| `%d` | a signed decimal integer |
| `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x` | an unsigned hexadecimal number, lowercase |
| `%X` | an unsigned hexadecimal number, uppercase |
| `%%` | a percent sign |

### Algorithm and data structure

No data structure is needed and nothing is allocated on the heap, so there is nothing to free.

1. `ft_printf` walks through the format string once, from left to right, using an index `i`.
2. A normal character is written directly and counted as 1.
3. When a `%` is found, the next character is passed to `handle_conversion`, together with the argument list. This function chooses the right printing function with a chain of `if` statements, and returns how many characters it wrote. The index then moves forward by 2 (the `%` and the conversion letter).
4. The counts of all pieces are added together, and the total is returned at the end. If the format ends with a lone `%`, the loop stops instead of reading past the end of the string.

Why this design:
- **One function per conversion** (`print_char`, `print_str`, `print_int`, ...). Each one reads its own argument with `va_arg` and returns its own count, so the main loop stays short and easy to follow, and each function respects the 25-line Norm limit.
- **Recursive digit printing** for numbers (`put_unsigned`, `put_hex`). Dividing by 10 or by 16 produces the digits from right to left, so the function first prints the left part with a recursive call, then prints the last digit. This avoids a buffer and avoids `malloc`.
- **A lookup string** (`"0123456789abcdef"` or `"0123456789ABCDEF"`) for hexadecimal, controlled by an `uppercase_flag`. One function therefore handles `%x`, `%X` and `%p`.
- **`unsigned long`** for the hexadecimal function, because a pointer is 64 bits wide.
- **Negative numbers** are converted through a `long` before negation, so `INT_MIN` is handled safely.

### Files

| File | Content |
|---|---|
| `ft_printf.c` | `ft_printf` and `handle_conversion` |
| `ft_printf_utils.c` | write helpers and `put_unsigned` |
| `ft_print_chars.c` | `%c`, `%s`, `%%` |
| `ft_print_numbers.c` | `%d`, `%i`, `%u` |
| `ft_print_hex.c` | `%x`, `%X`, `%p` |
| `ft_printf.h` | prototypes and includes |
| `Makefile` | builds `libftprintf.a` |

## Instructions

### Compilation

```bash
make        # builds libftprintf.a
make clean  # removes the object files
make fclean # removes the object files and libftprintf.a
make re     # fclean, then make
```

The library is created with `ar rcs`. Running `make` a second time does not relink anything.

### Usage

Include the header in your code and link the library:

```c
#include "ft_printf.h"
```

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -I. -o test
```

### Testing

Create a file named `main.c` next to the Makefile, copy the following test into it, and run it. It prints each case with `ft_printf` and with the real `printf`, and shows the two returned lengths so they can be compared.

```c
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	a;
	int	b;
	int	n;

	n = 42;
	a = ft_printf("%c|%s|%d|%i|%u|%x|%X|%%\n", 'A', "hi", -42, 42, 3000000000u,
			255, 255);
	b = printf("%c|%s|%d|%i|%u|%x|%X|%%\n", 'A', "hi", -42, 42, 3000000000u,
			255, 255);
	printf("chars:  mine = %d, real = %d\n\n", a, b);
	a = ft_printf("%d %d %d\n", 0, INT_MAX, INT_MIN);
	b = printf("%d %d %d\n", 0, INT_MAX, INT_MIN);
	printf("ints:   mine = %d, real = %d\n\n", a, b);
	a = ft_printf("%u %x %X\n", UINT_MAX, 0, UINT_MAX);
	b = printf("%u %x %X\n", UINT_MAX, 0, UINT_MAX);
	printf("unsig:  mine = %d, real = %d\n\n", a, b);
	a = ft_printf("[%s] [%s] [%c]\n", "", (char *)NULL, 'z');
	b = printf("[%s] [%s] [%c]\n", "", (char *)NULL, 'z');
	printf("strs:   mine = %d, real = %d\n\n", a, b);
	a = ft_printf("%p %p\n", &n, (void *)0);
	b = printf("%p %p\n", &n, (void *)0);
	printf("ptrs:   mine = %d, real = %d\n", a, b);
	return (0);
}
```

```bash
make
cc -Wall -Wextra -Werror main.c libftprintf.a -I. -o test
./test
```

How to read the result:
- Each pair of lines (mine, then real) must look identical, and the two numbers on every `mine = ... real = ...` line must be equal.
- The address printed by `%p` changes between runs, but it must be the same in both lines of one run.
- For `NULL`, `%p` prints `(nil)` on Linux and `0x0` on macOS. The expected result is whatever the real `printf` prints on the machine you are using.
- Do not add `main.c` to the project's source list. It is only a test program.

Optional memory check:

```bash
valgrind --leak-check=full ./test      # Linux
leaks --atExit -- ./test               # macOS
```

## Resources

- `man 3 printf`, `man 3 stdarg`, `man 2 write`: behavior of `printf`, variadic functions and the `write` system call.
- The GNU C Library manual, section on variadic functions: https://www.gnu.org/software/libc/manual/
- The 42 Norm, for the rules about function length, parameters and forbidden keywords.

### AI usage

An AI assistant (Claude) was used as a tutor during this project, in a question-driven way rather than to generate the solution. It was used for:
- Explaining concepts: how `va_list`, `va_start`, `va_arg` and `va_end` work, and why `char` is promoted to `int` in variadic calls,
- Drafting this README, which I reviewed and adjusted.

The code in the `.c` and `.h` files was written and typed by me, and I tested it and I am able to explain every part of it.
