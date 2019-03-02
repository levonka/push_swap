#include "../inc/push_swap.h"

int		ind_a(t_st *st, int n)
{
	if (st->a_top + n < st->end + 1 && n >= 0)
		return (st->a_top + n);
	if (n < 0)
	{
		if (st->a_top + n >= 0)
			return (st->a_top + n);
		else
			return (st->end);
	}
	else
		return ((st->a_top + n) % (st->end + 1));
	return (0);
}

int		ind_b(t_st *st, int n)
{
	if (st->b_top + n < st->end + 1 && n >= 0)
		return (st->b_top + n);
	if (n < 0)
	{
		if (st->b_top + n >= 0)
			return (st->b_top + n);
		else
			return (st->end);
	}
	else
		return ((st->b_top + n) % (st->end + 1));
	return (0);
}

int		main(int ac, char **av)
{
	t_st	*stacks;
	char	*instructions;

	if (ac == 1)
		printerror(40);
	stacks = (t_st *)malloc(sizeof(t_st));
	ac = argsamount(ac, av);
	malloc_stack(stacks, ac);
	argvalidation(ac, av, stacks);
	ft_printf("\n%.clr\n", "========== TAB ===========");
	print_tab(stacks);
	diag(stacks);
	handle_instructions(stacks);
	return (0);
}
