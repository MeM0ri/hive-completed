#!bin/bash
#./norm_with_find.sh

find . -type f -name '*.c' ! -name 'main.c' -exec norminette -R CheckForbiddenSourceHeadders {} \;
