#include "../inc/push_swap.h"

void	sa(t_st *st)
{
	if (st->a_size > 1)
		ft_swapint(&st->a[st->a_top], &st->a[ind_a(st, 1)]);
}

void	sb(t_st *st)
{
	if (st->b_size > 1)
		ft_swapint(&st->b[st->b_top], &st->b[ind_b(st, 1)]);
}

void	ss(t_st *st)
{
	sa(st);
	sb(st);
}

void	pa(t_st *st)
{
	if (st->b_size > 0)
	{
		st->a[ind_a(st, -1)] = st->b[st->b_top];
		st->a_size++;
		st->a_top = ind_a(st, -1);

		st->b_size--;
		st->b_top = ind_b(st, 1);
	}
}

void	pb(t_st *st)
{
	if (st->a_size > 0)
	{
		st->b[ind_b(st, -1)] = st->a[st->a_top];
		st->b_size++;
		st->b_top = ind_b(st, -1);

		st->a_size--;
		st->a_top = ind_a(st, 1);
	}
}

void	ra(t_st *st)
{
	if (st->a_size >= 2)
	{
		st->a[ind_a(st, st->a_size)] = st->a[st->a_top];
		st->a_top = ind_a(st, 1);
	}
}

void	rb(t_st *st)
{
	if (st->b_size >= 2)
	{
		st->b[ind_b(st, st->b_size)] = st->b[st->b_top];
		st->b_top = ind_b(st, 1);
	}
}

void	rr(t_st *st)
{
	ra(st);
	rb(st);
}

void	rra(t_st *st)
{
	if (st->a_size >= 2)
	{
		st->a[ind_a(st, -1)] = st->a[ind_a(st, st->a_size - 1)];
		st->a_top = ind_a(st, -1);
	}
}

void	rrb(t_st *st)
{
	if (st->b_size >= 2)
	{
		st->b[ind_b(st, -1)] = st->b[ind_b(st, st->b_size - 1)];
		st->b_top = ind_b(st, -1);
	}
}

void	rrr(t_st *st)
{
	rra(st);
	rrb(st);
}

void	handle_instructions(t_st *st)
{
	ft_printf("%.clr\n", "=========== PB ===========");

	// rra(st);
	// pb(st);
	// sa(st);
	// rra(st);
	// pa(st);
	// pb(st);
	// rra(st);
	// pa(st);
	// ra(st);
	// ra(st);
	// pb(st);
	// pb(st);
	// rb(st);
	// sa(st);
	// rb(st);
	// pa(st);
	// ra(st);
	// pb(st);
	// sa(st);
	// pb(st);
	// pb(st);
	// sb(st);
	// rb(st);
	// rb(st);
	// pa(st);
	// pa(st);
	// sa(st);
	// pa(st);
	// ra(st);
	// pa(st);
	// ra(st);

	// int i = 0;
	// while (i < 4)
	// {
	// 	printf("%d\n", st->a[i]);
	// 	i++;
	// }
	// printf("hel\n");


	print_tab(st);
	diag(st);
}

