make && gcc -g -fsanitize=address test.c -L. -lft && ./a.out $@
# make && gcc -g -fsanitize=address test.c -L. -lftprintf -lft && ./a.out
