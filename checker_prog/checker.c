#include "../inc/push_swap.h"

void	make_tab(t_st *st, int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		st->a[i - 1] = ft_atoi(av[i]);
		i++;
	}
	// st->a_top = ac - 2;
	st->a_top = 0;
	st->a_size = ac - 1;
}

int		main(int ac, char **av)
{
	t_st	*stacks;

	stacks = (t_st *)malloc(sizeof(t_st));
	malloc_stack(stacks, ac);
	// argvalidation(ac, av);
	make_tab(stacks, ac, av);
	// ft_printf("\n%.clr\n", "======== TAB =========");
	print_tab(stacks);
	// ft_printf("\n");
	diag(stacks);
	// handle_instructions(stacks);
	return (0);
}

void	diag(t_st *st)
{
	ft_printf("\n");
	ft_printf("|%.3clr %3d|\t", "a_top =", st->a_top);
	ft_printf("|%.3clr %3d|\n", "a_size =", st->a_size);
	ft_printf("|%.2clr %3d|\t", "b_top =", st->b_top);
	ft_printf("|%.2clr %3d|\n", "b_size =", st->b_size);
	ft_printf("\n");
}