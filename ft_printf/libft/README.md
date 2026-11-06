*This project has been created as part of the 42 curriculum by mgencogl*

# Description

The objective of this project is to recode a collection of standard C library functions, alongside additional utility routines, from scratch. 

This will serve as the core utility toolkit for future 42 projects since most standard C library is forbidden for most projects. 

The project solidifies a deep understanding on memory management, pointer manipulation and arithmetics, string formatting, and data structures like linked lists.

## Library Description

The library consists of three distinct segments: *Standard libc adaptations*, *utility expansions*, and *linked-list features*. Norms applied adheres to the *42 Norminette* limitations. 

### Standard Libc functions

Following functions of the standard libc is reimplemented with the same prototypes and behaviours, adhering strictly to their definitions on the `man` page. Only difference is the names are with a prefix "ft_".
* isalpha
* isdigit
* isalnum
* isascii
* isprint
* strlen
* memset
* bzero
* memcpy
* memmove
* strlcpy
* strlcat
* toupper
* tolower
* strchr
* strrchr
* strncmp
* memchr
* memcmp
* strnstr
* atoi

# Instructions

This library is compiled into a static archive file named libft.a using a Makefile tool. 

## Compilation

To compile mandatory elements, navigate to the root directory and run this bash command:

`make`

## Installation

Some other useful bash commands (which can be edited through Makefile tool)

`make clean`: Remove all temporary object files (`.o` files).
`make fclean`: Does `make clean` and also removes the library archive `libft.a`
`make re`: It executes `fclean` and then `make all` in succession.

## Execution/Usage

To link and use this custom library archive within a C application: Include (`#include "libft.h"`) the header definition reference inside your script files. 

Also compile your application alongside `libft.a` with the following bash command:

`cc -Wall -Wextra -Werror main.c -L. -lft -o program`

# Resources

## AI Usage
An AI collaborator was utilized during the development of this library to assist in code auditing, debugging edge-case logic and layout compliance (norminette).

Specific tasks where AI collaboration included:
* `ft_strnstr`: Audited long conditional boundaries
* `ft_strtrim` and `ft_memmove`: Identified `size_t` vulnerability to mitigate algorithmic underflow. Restructured the reverse indexing routine to prevent looping below zero.
* `ft_split` and `ft_lstmap`: Verified 2 dimensional allocation patterns including double level pointers. Safely triggering localized malloc rollbacks `free_all` logic. To preserve zero-leak execution. Also assisted with compressing the complex `ft_create_words` architecture to under 25-line limit. 

## References
The conceptual fixes and technical logic rules were derived from and verified against the following industry standards and official manuals:

* **ISO C Standard Defs:** (https://pubs.opengroup.org/onlinepubs/009696599 "POSIX reference") 
* **The Linux Programmer's Manual:** [Linux Man Pages](https://man7.org).
* **Forward vs. backwards copy directions**:[GeeksforGeeks C++ memmove Implementation Guides](https://www.geeksforgeeks.org/cpp/write-memcpy/) to handle memory shifts without data corruption.