NAME = push_swap

LIB = libft/libftprintf.a

CHECKNAME = checker
# MAIN_CHECKER = checker_prog/checker.c
CHECKER_SRC = checker_prog/*.c

PUSHNAME = push_swap
# MAIN_PUSH = push_swap_prog/push_swap.c
PUSH_SRC = push_swap_prog/*.c

GNL = get_next_line.c
COMMON_FUNCS = common_funcs/*.c

MLX = mlx/*.c

FLAGS = -Wall -Wextra -Werror

OBJ = *.o

INC = inc/push_swap.h

all: $(NAME)

$(NAME):

common: fclean
	@make -C libft
	@gcc $(FLAGS) -c $(GNL) $(MLX) $(COMMON_FUNCS) -I$(INC)

push_swap: common checker
	@gcc $(FLAGS) -c $(PUSH_SRC) -I$(INC)
	@gcc -lmlx -framework OpenGL -framework AppKit -L. $(LIB) -I$(INC) -o $(PUSHNAME) $(OBJ)
	@make clean

checker:
	@gcc $(FLAGS) -c $(CHECKER_SRC) -I$(INC)
	@gcc -lmlx -framework OpenGL -framework AppKit -L. $(LIB) -I$(INC) -o $(CHECKNAME) $(OBJ)
	@/bin/rm -f checker.o

norme:
	norminette $(MAIN_CHECKER)

clean:
	@/bin/rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@/bin/rm -f $(CHECKNAME)
	@/bin/rm -f $(PUSHNAME)
	@make -C libft fclean

re: fclean all
