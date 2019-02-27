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
	st->a_end = ac - 2;
}

int		ind(t_st *st, int topa)
{
	if (topa + st->a_top < st->a_end + 1)
	{
		return (st->a_top + topa);
	}
	else
		return ((st->a_top + topa) % (st->a_end + 1));
	return (0);
}

int		main(int ac, char **av)
{
	t_st	*stacks;

	stacks = (t_st *)malloc(sizeof(t_st));
	malloc_stack(stacks, ac);
	// argvalidation(ac, av);
	make_tab(stacks, ac, av);
	ft_printf("\n%.clr\n", "======== TAB =========");
	print_tab(stacks);
	diag(stacks);
	// printf("ind = %d\n", ind(stacks, 1));
	// ft_printf("\n");
	handle_instructions(stacks);
	return (0);
}
