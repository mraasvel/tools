# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/25 18:39:35 by mraasvel      #+#    #+#                  #
#    Updated: 2020/11/27 19:43:48 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = calc.exe
SRC = $(shell find $(SRCDIR) -name "*.c" -exec basename {} \;)
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

CC = gcc
DEBUG = -O0 -g -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
IFLAG = -I $(IDIR)
LFLAG = -L$(LDIR) -lft -lftprintf

OBJDIR = obj
SRCDIR = src
IDIR = include
LDIR = libs

vpath %.c src

all: dep $(NAME)
.PHONY: all clean fclean re

dep:
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJ) Makefile
	$(CC) -o $@ $(DEBUG) $(OBJ) $(LFLAG)
$(OBJDIR)/%.o: %.c
	$(CC) -o $@ -c $< $(IFLAG)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
