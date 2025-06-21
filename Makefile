# Project: minitalk
MAKEFLAGS += --no-print-directory
NAME_SERVER := server
NAME_CLIENT := client

# Compiler and flags
CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f

# Function to set show commands or not
QUIET = $(if $(filter 0,$(VERBOSE)),@,)

# Files
SRCS_SERVER := server.c
SRCS_CLIENT := client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

LIBFT := libft/libft.a

all: $(NAME_SERVER) $(NAME_CLIENT)

# Link the object files to create the executable
$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	$(QUIET)$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER) $(LIBFT)

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(QUIET)$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT) $(LIBFT)

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
	$(QUIET)$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)
	$(QUIET)make clean -C libft

fclean: clean
	$(QUIET)$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	$(QUIET)make fclean -C libft
f: fclean

# Rebuild rules
re: fclean all

doc:
	doxygen Doxyfile

.PHONY: all clean fclean re