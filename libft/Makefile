# C sources
CSRC := ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
CSRCB := ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
		ft_lstiter.c ft_lstmap.c
# Create object files from C sources files
OSRC = $(CSRC:.c=.o)
OSRCB = $(CSRCB:.c=.o)

# Define path to the library
QUIET ?= @

# Define flags
FLAGS := -Wall -Werror -Wextra

# Define compiler type (if not define by default gcc)
CC := cc

# Sortcat for remove comand
RM := rm -f

# Define program name
NAME := libft.a

# Define how must compile all C files to O files
# compiler|flags|only compile|$< current file name|set name as|replace file type .c to .o
.c.o:
	$(QUIET)${CC} ${FLAGS} -c $< -o $@

# Build my library
# ar - Create/Modify archive
# r - add/replace files
# c - create new archive
# s - create symbol index
${NAME}: ${OSRC}
	$(QUIET)ar rcs $@ $^

# Build my library
all: ${NAME}

bonus: ${NAME} ${OSRCB}
	$(QUIET)ar rcs ${NAME} ${OSRCB}

# clean obj files only ${OSRCB}
clean:
	$(QUIET)${RM} ${OSRC} ${OSRCB}

# clean all files ${bonus}
fclean: clean
	$(QUIET)${RM} ${NAME} ${bonus}

# clean all files and compile again
re: fclean all

.PHONY : all bonus re clean fclean
