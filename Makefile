# Project: minitalk
MAKEFLAGS += --no-print-directory
NAME_SERVER := server
NAME_CLIENT := client
NAME_SERVER_BONUS := server_bonus
NAME_CLIENT_BONUS := client_bonus

# Compiler and flags
CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f

# Function to set show commands or not
QUIET = $(if $(filter 0,$(VERBOSE)),@,)

# Files
SRCS_SERVER := server.c
SRCS_CLIENT := client.c
SRCS_SERVER_BONUS := server_bonus.c
SRCS_CLIENT_BONUS := client_bonus.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

LIBFT := libft/libft.a

all: $(NAME_SERVER) $(NAME_CLIENT)

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

# Link the object files to create the executable
$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	$(QUIET)$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER) $(LIBFT)

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(QUIET)$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT) $(LIBFT)

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS) $(LIBFT)
	$(QUIET)$(CC) $(CFLAGS) -o $(NAME_SERVER_BONUS) $(OBJS_SERVER_BONUS) $(LIBFT)

$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS) $(LIBFT)
	$(QUIET)$(CC) $(CFLAGS) -o $(NAME_CLIENT_BONUS) $(OBJS_CLIENT_BONUS) $(LIBFT)

# Object file generation rules
%.o: %.c
	$(QUIET)$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(QUIET)make -C libft fclean
	$(QUIET)make -C libft

# Clean rules
clean:
	$(QUIET)$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
	$(QUIET)make clean -C libft

fclean: clean
	$(QUIET)$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
	$(QUIET)make fclean -C libft
f: fclean

# Rebuild rules
re: fclean all

doc:
	doxygen Doxyfile

.PHONY: all clean fclean re