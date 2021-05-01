# Executable
NAME := a.out


# Directories
SDIR := src
ODIR := obj/
DDIR := dep/
IDIR := includes
LDIR := libs

# Files
SRC := $(shell find $(SDIR) -name "*.c" -type f)
OBJ := $(patsubst $(SDIR)/%.c,$(ODIR)%.o,$(SRC))
DEP := $(patsubst $(SDIR)/%.c,$(DDIR)%.d,$(SRC))
HDF := $(shell find $(IDIR) -name "*.h" -type f)

# Compilation
CC = gcc
IFLAGS = -I$(IDIR)
LFLAGS =
# CFLAGS = -Wall -Wextra
CFLAGS =
ifeq ($(shell uname -s),Linux)
DFLAGS := -O0 -g -fsanitize=address -fsanitize=leak
else
DFLAGS := -O0 -g -fsanitize=address
endif
CFLAGS += $(DFLAGS)

RM = /bin/rm -f

# Rules
.PHONY: all
all:
	$(MAKE) -j4 $(NAME)

# Compilation
$(NAME): $(SRC) $(HDF)
	@echo Compiling $@
	@$(MAKE) $(OBJ)
	@$(CC) -o $@ $(OBJ) $(CFLAGS) $(LFLAGS)
$(OBJ): $(ODIR)%.o: $(SDIR)/%.c
	@echo Compiling $@
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $< $(CFLAGS) $(IFLAGS)
$(DDIR)%.d: $(SDIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $< -MM -MF $@ -MT $(ODIR)$*.o $(IFLAGS)

# Cleanup
.PHONY: clean fclean re cleanall
clean:
	$(RM) $(OBJ)
	$(RM) $(DEP)
fclean: clean
	$(RM) $(NAME)
cleanall: fclean
	$(RM) -r $(DDIR)
	$(RM) -r $(ODIR)
re: fclean
	$(MAKE) all

-include $(DEP)
