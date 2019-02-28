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
		st->a_top--;

		st->b_size--;
		st->b_top++;
	}
}

void	pb(t_st *st)
{
	if (st->a_size > 0)
	{
		st->b[ind_b(st, -1)] = st->a[st->a_top];
		st->b_size++;
		st->b_top--;

		st->a_size--;
		st->a_top++;
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
		st->a[st->a_top] = st->a[(st->a_top + st->a_size) % (st->a_size + 1)];
		st->a_top = (st->a_top + st->a_size) % (st->a_size + 1);
	}
}

void	handle_instructions(t_st *st)
{
	ft_printf("%.clr\n", "========= PB =========");
	pb(st);
	// pb(st);
	// rra(st);
	// rra(st);
	// st->a_size = 4;
	// st->a_top = 0;
	// top = 1

	// top = 0
	// st->a[0] = st->a[3];
	// top = 3 + 3 % (3 + 1) = 2
	// st->a[3] = st->a[2];
	// top = 2 + 3 % 4 = 1
	// st->a[2] = st->a[1];
	// top = 1
	// st->a[1] = st->a[0];
	// top = 0
	// st->a[0] = st->a[3];
	// st->a[3] = st->a[2];
	// st->a[2] = st->a[1];
	// st->a[1] = st->a[0];
	// printf("%d\n", ind_a(st, st->a_size - 1));
	// st->a_top = ind_a(st, st->a_size);
	print_tab(st);
	diag(st);
	// ft_printf("%.clr\n", "========= RB =========");
	// rb(st);
	// print_tab(st);
	// diag(st);
	// pa(st);
	// ra(st);
	// pb(st);
	// print_tab(st);
	// diag(st);
}



// 1
// 2
// 3
// 4
// 5

// pb pb
// 1~
// 2~
// 3 - top
// 4
// 5

// size = 3.
// top = 2.

// ra
// 3
// 2~
// 3~
// 4 - top
// 5

// a[(top + size) % end] = a[top];	(2 + 3) % 4 = 5 % 4 = 1;
// top++;
// size = 3.
// top = 3.

// ra
// 3
// 4
// 3~
// 4~
// 5 - top

// ra
// 3 - top
// 4
// 5
// 4~
// 5~



// 1
// 2
// 3
// 4
// 5

// pb
// 1
// top = 0
// end = 0

// pb
// 2
// 1
// top = 1
// end = 1

// pb
// 3
// 2
// 1
// top = 2
// end = 2
// size = 3

