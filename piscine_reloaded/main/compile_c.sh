#!/bin/bash
#./compile_c.sh
gcc -Wall -Wextra -Werror $(find . -name '*.c' ! -name 'ft_print_params.c' ! -name 'ft_sort_params.c')
