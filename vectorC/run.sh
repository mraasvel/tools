make && gcc -g -fsanitize=address main.c -L. -lvect && ./a.out
