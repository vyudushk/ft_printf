NAME		= libftprintf.a
FILENAMES	= ft_printf.c ft_itoa_base.c
HEADER		= .
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
LIBFT		= libft/libft.a

SRC			= $(addprefix src/, $(FILENAMES))
OBJ			= $(addprefix build/, $(FILENAMES:.c=.o))

.PHONY: all clean fclean re test

all : $(LIBFT) $(NAME)

$(OBJ): $(SRC) | build
	gcc $(FLAGS) -c -I$(HEADER) -I libft $(SRC)
	mv $(FILENAMES:.c=.o) build

$(NAME): $(LIBFT) $(OBJ)
	ar rc $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	make -C libft

build:
	mkdir build

clean:
	rm -rf build
	rm -f $(NAME)
	make fclean -C libft

fclean: clean
	rm -rf $(NAME)

re: fclean all
