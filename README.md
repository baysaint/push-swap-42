*This project has been created as part of the 42 curriculum by mgencogl*

# Decsription

This project recreates printf with the conversions `cspdiuxX%`.
It prints to standard output (file descriptor = 1) and returns the number of characters printed.

I read the format string character by character. When I find a conversion, I use `va_arg` to get the argument and call the corresponding function.

Numbers are converted into allocated strings using division and remainder. These strings are freed after printing.

I use a `va_list`, an index and a character counter because everything is processed in order, without needing a more complex data structure.

# Instructions

Run `make` to create `libftprintf.a`.

Include `ft_printf.h` in your main and compile:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf
./test_printf
```
The libft sources, header and Makefile must be in the `libft` folder.

- `make clean`: remove object files.
- `make fclean`: remove object files and libraries.
- `make re`: rebuild everything.


# Resources

- The project subject.
- Manual pages: `printf`, `stdarg`, `write`, `malloc` and `free`.

I used AI when needed to better understand some concepts, debug my code, and create tests to compare my ft_printf with the original printf. I also used it to help write this README.
