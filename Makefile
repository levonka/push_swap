NAME = push_swap

CHECKNAME = checker
MAIN_CHECKER = checker_prog/checker.c
CHECKER_SRC = checker_prog/*.c

SORTNAME = sorting
MAIN_SORT = main_sort.c
SORTING_SRC = sorting_algorithms/*.c

FLAGS = -Wall -Wextra

OBJ = *.o

INC = inc/push_swap.h
# includes/ft_printf.h includes/libft.h

all: $(NAME)

$(NAME): checker sort

checker: clean
	@gcc $(FLAGS) -c $(MAIN_CHECKER) $(CHECKER_SRC) -I$(INC)
	@gcc -L. -lftprintf -I$(INC) -o $(CHECKNAME) $(OBJ)
	@make clean

sort: clean
	@gcc $(FLAGS) -c $(MAIN_SORT) $(SORTING_SRC) -I$(INC)
	@gcc -L. -lftprintf -I$(INC) -o $(SORTNAME) $(OBJ)
	@make clean

norme:
	norminette $(SRC)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(CHECKNAME)
	@/bin/rm -f $(SORTNAME)

re: fclean all
