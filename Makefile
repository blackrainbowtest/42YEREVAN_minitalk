# Project: minitalk
MAKEFLAGS += --no-print-directory
NAME := minitalk

# Compiler and flags
CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f

# Function to set show commands or not
QUIET = $(if $(filter 0,$(VERBOSE)),@,)

# Files
SRCS := client.c server.c
OBJS := $(SRCS:.c=.o)

LIBFT := libft/libft.a
GNL := get_next_line/get_next_line.a

all: $(NAME)

# Link the object files to create the executable
$(NAME): $(OBJS) $(LIBFT)
	$(QUIET)$(CC) $(OBJS) $(LIBFT) -o $(NAME)

# Object file generation rules
%.o: %.c
	$(QUIET)$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(QUIET)make -C libft fclean
	$(QUIET)make -C libft

$(GNL):
	$(QUIET)make -C get_next_line fclean
	$(QUIET)make -C get_next_line

# Clean rules
clean:
	$(QUIET)$(RM) $(OBJS)
	$(QUIET)make clean -C libft

fclean: clean
	$(QUIET)$(RM) $(NAME)
	$(QUIET)make fclean -C libft

# Rebuild rules
re: fclean all

.PHONY: all clean fclean re