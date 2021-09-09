#!/bin/bash

clang -Wall -Werror -Wextra -fsanitize=address -g dlst_test.c dlst.c -I$FT -L$FT -lft && ./a.out
