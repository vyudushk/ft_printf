NAME		= libftprintf.a
FILENAMES	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c 
FILENAMES	+= ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c 
FILENAMES	+= ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c 
FILENAMES	+= ft_strcmp.c ft_strstr.c ft_strnstr.c ft_atoi.c ft_isalpha.c ft_isdigit.c
FILENAMES	+= ft_isalnum.c ft_isascii.c ft_isprint.c ft_isprint.c ft_toupper.c
FILENAMES	+= ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c
FILENAMES	+= ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c
FILENAMES	+=  ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c
FILENAMES	+= ft_strtrim.c ft_strsplit.c ft_strncmp.c ft_itoa.c
FILENAMES	+= ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c
FILENAMES	+= ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
FILENAMES	+= ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c
FILENAMES	+= ft_lstiter.c ft_lstmap.c 
FILENAMES	+= ft_isupper.c ft_islower.c ft_intlen.c ft_iswhite.c ft_strrev.c
FILENAMES	+= ft_strndup.c get_next_line.c
FILENAMES	+= ft_putnstr_fd.c

FILENAMES	+= ft_printf.c ft_itoa_base.c tab.c cast.c saveline.c handle_print.c
HEADER		= includes
FLAGS		= -Wall -Wextra -Werror
TEST		= runtest

SRC			= $(addprefix src/, $(FILENAMES))
OBJ			= $(addprefix build/, $(FILENAMES:.c=.o))

CC			= gcc

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) 

build/%.o: src/%.c | build
	$(CC) -g $(FLAGS) -I $(HEADER) -c $^ -o $@

build:
	mkdir build

test: $(NAME)
	$(CC) $(FLAGS) test.c -I $(HEADER) $(NAME) -o $(TEST)

debug: $(NAME)
	$(CC) -g $(FLAGS) test.c -I $(HEADER) $(NAME) -o $(TEST)

clean:
	rm -rf build
	rm -f runme
	rm -rf runtest.dSYM
	rm -f $(TEST)

fclean: clean
	rm -f $(NAME)

re: fclean all
