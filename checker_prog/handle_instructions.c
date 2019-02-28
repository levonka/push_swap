#include "../inc/push_swap.h"

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
		if (st->b_top == -1)
			st->b_top = st->b_end;
		st->b_size--;

		st->a_size++;
	}
}

void	pb(t_st *st)
{
	if (st->a_size > 0)
	{
		st->b[st->b_size] = st->a[st->a_top];
		// st->b_top++;
		st->b_end++;
		st->b_size++;
		st->a_size--;
		if (st->a_top == st->a_end)
			st->a_top = 0;
		else
			st->a_top++;
		if (st->b_top == -1)
			st->b_top = st->b_end;
		else
			st->b_top++;
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
	{
		if (st->a_end == st->a_size - 1)
		{
			if (st->a_top == st->a_end)
				st->a_top = 0;
			else
				st->a_top++;
			return ;
		}
		if ((st->a_top + st->a_size - 1) >= st->a_end)
			st->a[(st->a_top + st->a_size - 1) % (st->a_end)] = st->a[st->a_top];
		else
			st->a[st->a_top + st->a_size] = st->a[st->a_top];
		if (st->a_top == st->a_end)
			st->a_top = 0;
		else
			st->a_top++;
	}
}

void	rb(t_st *st)
{
	if (st->b_size > 1)
		st->b_top--;
	if (st->b_top < 0)
		st->b_top = st->b_end;

	// printf("\n");
	// int i;
	// i = 0;
	// while (i < st->b_size + 3)
	// {
	// 	printf("%d\n", st->b[i]);
	// 	i++;
	// }
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
	pb(st);
	pb(st);
	pb(st);
	rb(st);
	rb(st);
	rb(st);
	rb(st);
	print_tab(st);
	diag(st);

	pa(st);
	pa(st);
	pa(st);
	pa(st);
	pa(st);
	ra(st);
	ra(st);
	ra(st);
	ra(st);
	// pb(st);
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

