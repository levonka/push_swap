NAME = libftprintf.a

LNAME = libft

SRCS = auxiliary/*.c processing/*.c to_ascii/*.c *.c

OBJ = *.o

OBJ2 = libft/ft_*.o

FLAGS = -Wall -Wextra -Werror

INC = ft_printf.h

all: $(NAME)

$(NAME):
	@make -C libft fclean && make -C libft
	@gcc $(FLAGS) -c $(SRCS) -I$(INC)
	@ar rc $(NAME) $(OBJ) $(OBJ2)
	@ranlib $(NAME)
	@/bin/rm -f $(OBJ)

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f $(OBJ2)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft/libft.a

re: fclean all
