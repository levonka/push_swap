#include "../inc/push_swap.h"

void	pb(t_st *st)
{
	if (st->a_size > 0)
	{
		st->b[st->b_size] = st->a[st->a_top];
		st->a_top++;
		st->b_top++;
		st->b_end++;
		st->b_size++;
		st->a_size--;
	}
}

void	pa(t_st *st)
{
	if (st->b_size > 0)
	{
		if (st->a_top > 0)
		{
			st->a[st->a_top - 1] = st->b[st->b_top];
			st->a_top--;
		}
		else
		{
			st->a[st->a_end] = st->b[st->b_top];
			st->a_top = st->a_end;
		}
		st->b_top--;
		st->b_end--;
		st->b_size--;

		st->a_size++;
	}
}

void	sa(t_st *st)
{
	if (st->a_size > 1)
		ft_swapint(&st->a[st->a_top], &st->a[st->a_top + 1]);
}

void	sb(t_st *st)
{
	if (st->b_size > 1)
		ft_swapint(&st->b[st->b_top], &st->b[st->b_top - 1]);
}

void	ss(t_st *st)
{
	if (st->a_size > 1)
		sa(st);
	if (st->b_size > 1)
		sb(st);
}

void	ra(t_st *st)
{
	if (st->a_size > 1)
		st->a_top++;
	if (st->a_top > st->a_end)
		st->a_top = 0 + st->a_size;
}

void	rb(t_st *st)
{
	if (st->b_size > 1)
		st->b_top--;
	if (st->b_top < 0)
		st->b_top = st->b_end;
}

void	rr(t_st *st)
{
	ra(st);
	rb(st);
}

void	handle_instructions(t_st *st)
{
	ft_printf("%.clr\n", "========= PB =========");
	pb(st);
	pb(st);
	// print_tab(st);
	// diag(st);
	// ft_printf("%.clr\n", "========= SA =========");
	// ft_printf("%.clr\n", "========= SB =========");
	// ft_printf("%.clr\n", "========= SS =========");
	// sb(st);
	// sa(st);
	// ss(st);
	// print_tab(st);
	// ft_printf("%.clr\n", "========= PA =========");
	// pa(st);
	// pa(st);
	// print_tab(st);
	// diag(st);
	// ft_printf("%.clr\n", "========= RA =========");
	// ft_printf("%.clr\n", "========= RB =========");
	// rr(st);
	// diag(st);
	ft_printf("%.clr\n", "========= RB =========");
	rr(st);
	rr(st);
	diag(st);

	// diag(st);
	print_tab(st);





}