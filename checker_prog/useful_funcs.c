#include "../inc/push_swap.h"

void	printerror(int status)
{
	ft_printf("Error\n");
	exit(status);
}

void	diag(t_st *st)
{
	ft_printf("\n");
	ft_printf("|%.3clr %3d|\t", "a_top =", st->a_top);
	ft_printf("|%.3clr %3d|\t", "a_end =", st->a_end);
	ft_printf("|%.3clr %3d|\n", "a_size =", st->a_size);
	ft_printf("|%.2clr %3d|\t", "b_top =", st->b_top);
	ft_printf("|%.2clr %3d|\t", "b_end =", st->b_end);
	ft_printf("|%.2clr %3d|\n", "b_size =", st->b_size);
	ft_printf("\n");
}

void	malloc_stack(t_st *stacks, int ac)
{
	static char status;

	if (status == 0)
	{
		stacks->a = (int *)malloc(sizeof(int) * ac);
		stacks->b = (int *)malloc(sizeof(int) * ac);
		stacks->b_top = -1;
		stacks->b_end = -1;
		stacks->b_size = 0;
		if (stacks == NULL || stacks->a == NULL || stacks->b == NULL)
			exit(3);
		status = 1;
	}
	else
	{
		free(stacks->a);
		free(stacks->b);
		free(stacks);
		status = 0;
	}
}


void	ft_swapint(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	print_tab(t_st *st)
{
	int     i;
	int		top_a;
	int		top_b;

	i = 0;
	top_a = st->a_top;
	top_b = st->b_top;
	ft_printf("%.3clr    %.2clr\n", "+stack a+", "+stack b+");
	while (i < st->a_size || i < st->b_size)
	{
		if (top_b == -1)
			top_b = st->b_end;
		if (top_a > st->a_end)
			top_a = 0;
		if (i < st->a_size)
			ft_printf("%.3clr%4d   %.3clr", "|", st->a[top_a], "|");
		else
			ft_printf("%.3clr   -   %.3clr", "|", "|");
		if (i < st->b_size)
			ft_printf("%5.2clr%4d   %.2clr\n", "|", st->b[top_b], "|");
		else
			ft_printf("%5.2clr   -   %.2clr\n", "|", "|");
		i++;
		top_a++;
		top_b--;
	}
	ft_printf("%.3clr    %.2clr\n", "|_______|", "|_______|");
}
