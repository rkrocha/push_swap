#!/bin/bash

clang -Wall -Werror -Wextra -fsanitize=address -g dlst.c stack.c stack_test.c -I$FT -L$FT -lft && ./a.out "$1"
