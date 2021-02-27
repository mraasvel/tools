
# Variables
NAME = a.out
SRC = $(shell find $(SRCDIR) -name "*.c" -type f -exec basename {} \;)
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
HEADERS = $(shell find $(IDIR) -name "*.h" -type f)
LIBS = $(shell find $(LIBDIR) -name "*.a" -type f)
DEPS = $(HEADERS) Makefile

# Directories
SRCDIR = src
OBJDIR = obj
IDIR = includes
LIBDIR = libs
vpath %.c $(SRCDIR)
vpath %.o $(OBJDIR)
vpath %.h $(IDIR)
vpath %.a $(LIBDIR)

# Compilation
CC = gcc
CFLAGS = -Wall -Wextra
IFLAGS = -I$(IDIR)
LIBFLAGS =

ifdef DEBUG
CFLAGS += -O0 -g -fsanitize=address
else
CFLAGS += -O3
endif


.PHONY: all
all:
	$(MAKE) libs
	$(MAKE) $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(OBJ) $(LIBFLAGS)
$(OBJDIR)/%.o:%.c $(DEPS) | $(OBJDIR)
	$(CC) -c -o $@ $(CFLAGS) $(IFLAGS) $<

.PHONY: libs
libs:
$(OBJDIR):
	mkdir -p $(OBJDIR)


.PHONY: clean fclean re debug
clean:
	rm -f $(OBJ)
fclean:
	$(MAKE) clean
	rm -f $(NAME)
re: fclean
	$(MAKE) all
debug:
	$(MAKE) re DEBUG=1
