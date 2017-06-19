LIB			= libftprintf.a
FILENAMES	= ft_printf.c
HEADER		= .
FLAGS		= -Wall -Wextra -Werror

SRC			= $($(FILENAMES))
OBJ			= $(addprefix build/, $(FILENAMES:.c=.o))

.PHONY: all clean fclean re test

all : $(LIB)

$(LIB): $(OBJ)
	ar rc $(LIB) $(OBJ)
	make -C libft

build/%.o: %.c | build
	gcc $(FLAGS) -I $(HEADER) -I libft -I. -c $^ -o $@

build:
	mkdir build

clean:
	rm -rf build
	rm -f $(LIB)
	make fclean -C libft

fclean: clean
	rm -rf $(NAME)

re: fclean all
