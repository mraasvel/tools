# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/14 18:22:13 by mraasvel      #+#    #+#                  #
#    Updated: 2021/02/15 21:17:48 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# file names
NAME = a.out
SRC = $(shell find $(SRCDIR) -name "*.c" -exec basename {} \;)
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
HEADERS = $(shell find $(IDIR) -name "*.h")
LIBFT = $(LIBDIR)/libft.a
DEPENDENCIES = $(HEADERS) Makefile

# compilation
CC = gcc
IFLAGS = -I $(IDIR)
LIBFLAG = -L$(LIBDIR) -lft
DFLAGS = -g -O0 -fsanitize=address
WFLAGS = -Wall -Wextra -Werror
CFLAGS =

# Directories
OBJDIR = obj
SRCDIR = src
LIBDIR = libs
IDIR = include
vpath %.c $(SRCDIR)
vpath %.o $(OBJDIR)

# Add debug flags
ifdef DEBUG
CFLAGS += $(DFLAGS)
else
CFLAGS += $(DFLAGS)
# CFLAGS += -O3
endif

.PHONY: all libft
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS) $(LIBFLAG)
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) -c -o $@ $< $(IFLAGS) $(CFLAGS)
$(LIBFT): $(LIBDIR)
	$(MAKE) -C ../libft
	cp ../libft/libft.a $(LIBDIR)
	cp ../libft/libft.h $(IDIR)

$(LIBDIR):
	mkdir -p $(LIBDIR)
$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY: clean fclean re debug
clean:
	rm -f $(OBJ)
fclean:
	$(MAKE) clean
	rm -f $(LIBFT)
	rm -f $(NAME)
re:
	$(MAKE) fclean
	$(MAKE) all
debug:
	$(MAKE) re DEBUG=1
