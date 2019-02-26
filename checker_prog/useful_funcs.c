#include "../inc/push_swap.h"

void	printerror(int status)
{
	ft_printf("Error\n");
	exit(status);
}

void	malloc_stack(t_st *stacks, int ac)
{
	static char status;

	if (status == 0)
	{
		stacks->a = (int *)malloc(sizeof(int) * ac);
		stacks->b = (int *)malloc(sizeof(int) * ac);
		stacks->b_top = -1;
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

void	print_tab(t_st *st)
{
	int     i;

	i = 0;
	ft_printf("%.3clr    %.2clr\n", "+stack a+", "+stack b+");
	// while (st->a_top - i >= 0 || st->b_top - i >= 0)
	// {
	// 	if (st->a_top - i >= 0)
	// 		ft_printf("%.3clr%4d   %.3clr", "|", st->a[st->a_top - i], "|");
	// 	else
	// 		ft_printf("%.3clr   -   %.3clr", "|", "|");
	// 	if (st->b_top - i >= 0)
	// 		ft_printf("%5.2clr%4d   %.2clr\n", "|", st->b[st->b_top - i], "|");
	// 	else
	// 		ft_printf("%5.2clr   -   %.2clr\n", "|", "|");
	// 	i++;
	// }
	while (i < st->a_size)
	{
		ft_printf("%.3clr%4d   %.3clr\n", "|", st->a[st->a_top - i], "|");
		i++;
	}
}
