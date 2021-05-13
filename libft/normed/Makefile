# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/14 12:06:33 by mraasvel      #+#    #+#                  #
#    Updated: 2021/05/13 11:47:21 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

include src.mk

SDIR = src
ODIR = obj
IDIR = includes

OBJ = $(patsubst $(SDIR)/%.c,$(ODIR)/%.o,$(SRC))

# Compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I$(IDIR) -I.

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^
$(OBJ): $(ODIR)/%.o: $(SDIR)/%.c
	@mkdir -p $(@D)
	$(CC) -o $@ -c $(CFLAGS) $< $(IFLAGS)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
