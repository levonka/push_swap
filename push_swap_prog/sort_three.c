#include "../inc/push_swap.h"

int		minimal_ind_a(t_st *st)
{
	// int		i;
	// int		min;

	// i = 0;
	// min = 0;
	// while (i + 1 < st->a_size)
	// {
	// 	if (st->a[ind_a(st, min)] > st->a[ind_a(st, i + 1)])
	// 		min = i + 1;
	// 	i++;
	// }

	if (st->a[ind_a(st, 0)] < st->a[ind_a(st, 1)] &&
		st->a[ind_a(st, 1)] < st->a[ind_a(st, 2)] &&
		st->a[ind_a(st, 0)] < st->a[ind_a(st, 2)])
		return (1);		// 1 2 3
	else if (st->a[ind_a(st, 0)] < st->a[ind_a(st, 1)] &&
		st->a[ind_a(st, 1)] > st->a[ind_a(st, 2)] &&
		st->a[ind_a(st, 0)] < st->a[ind_a(st, 2)])
		return (2);		// 1 3 2
	else if (st->a[ind_a(st, 0)] > st->a[ind_a(st, 1)] &&
		st->a[ind_a(st, 1)] < st->a[ind_a(st, 2)] &&
		st->a[ind_a(st, 0)] < st->a[ind_a(st, 2)])
		return (3);		// 2 1 3
	else if (st->a[ind_a(st, 0)] < st->a[ind_a(st, 1)] &&
		st->a[ind_a(st, 1)] > st->a[ind_a(st, 2)] &&
		st->a[ind_a(st, 0)] > st->a[ind_a(st, 2)])
		return (4);		// 2 3 1
	else if (st->a[ind_a(st, 0)] > st->a[ind_a(st, 1)] &&
		st->a[ind_a(st, 1)] < st->a[ind_a(st, 2)] &&
		st->a[ind_a(st, 0)] > st->a[ind_a(st, 2)])
		return (5);		// 3 1 2
	else if (st->a[ind_a(st, 0)] > st->a[ind_a(st, 1)] &&
		st->a[ind_a(st, 1)] > st->a[ind_a(st, 2)] &&
		st->a[ind_a(st, 0)] > st->a[ind_a(st, 2)])
		return (6);		// 3 2 1
	return (0);
}

int		minimal_ind_b(t_st *st)
{
	if (st->b[ind_b(st, 0)] < st->b[ind_b(st, 1)] &&
		st->b[ind_b(st, 1)] < st->b[ind_b(st, 2)] &&
		st->b[ind_b(st, 0)] < st->b[ind_b(st, 2)])
		return (1);		// 1 2 3
	else if (st->b[ind_b(st, 0)] < st->b[ind_b(st, 1)] &&
		st->b[ind_b(st, 1)] > st->b[ind_b(st, 2)] &&
		st->b[ind_b(st, 0)] < st->b[ind_b(st, 2)])
		return (2);		// 1 3 2
	else if (st->b[ind_b(st, 0)] > st->b[ind_b(st, 1)] &&
		st->b[ind_b(st, 1)] < st->b[ind_b(st, 2)] &&
		st->b[ind_b(st, 0)] < st->b[ind_b(st, 2)])
		return (3);		// 2 1 3
	else if (st->b[ind_b(st, 0)] < st->b[ind_b(st, 1)] &&
		st->b[ind_b(st, 1)] > st->b[ind_b(st, 2)] &&
		st->b[ind_b(st, 0)] > st->b[ind_b(st, 2)])
		return (4);		// 2 3 1
	else if (st->b[ind_b(st, 0)] > st->b[ind_b(st, 1)] &&
		st->b[ind_b(st, 1)] < st->b[ind_b(st, 2)] &&
		st->b[ind_b(st, 0)] > st->b[ind_b(st, 2)])
		return (5);		// 3 1 2
	else if (st->b[ind_b(st, 0)] > st->b[ind_b(st, 1)] &&
		st->b[ind_b(st, 1)] > st->b[ind_b(st, 2)] &&
		st->b[ind_b(st, 0)] > st->b[ind_b(st, 2)])
		return (6);		// 3 2 1
	return (0);
}

void		sortthree_a(t_st *st, int size)
{
	int		min;

	min = minimal_ind_a(st);
	if (size == 3)
	{
		if (min == 1)
		{
		}
		else if (min == 2)
		{
			printf("ra\nsa\nrra\n");
			ra(st);
			sa(st);
			rra(st);
		}
		else if (min == 3)
		{
			printf("sa\n");
			sa(st);
		}
		else if (min == 4)
		{
			printf("rra\n");
			rra(st);
		}
		else if (min == 5)
		{
			printf("ra\n");
			ra(st);
		}
		else if (min == 6)
		{
			printf("sa\nrra\n");
			sa(st);
			rra(st);
		}
	}
	else
	{
		if (st->a[ind_a(st, 0)] > st->a[ind_a(st, 1)])
		{
			printf("sa\n");
			sa(st);
		}
	}



	// if (st->a[ind_a(st, 0)] > st->a[ind_a(st, 1)])
	// {
	// 	write(1, "sa\n", 3);
	// 	sa(st);
	// }
	// if (min == 0)
	// {
	// 	write(1, "rra\n", 4);
	// 	rra(st);
	// }
	// else if (min == 1)
	// {
	// 	write(1, "ra\n", 3);
	// 	ra(st);
	// }
}

void		sortthree_b(t_st *st, int size)
{
	int		min;

	min = minimal_ind_b(st);
	if (size == 3)
	{
		if (min == 1)
		{
		}
		else if (min == 2)
		{
			printf("rb\nsb\nrrb\n");
			rb(st);
			sb(st);
			rrb(st);
		}
		else if (min == 3)
		{
			printf("sb\n");
			sb(st);
		}
		else if (min == 4)
		{
			printf("rrb\n");
			rrb(st);
		}
		else if (min == 5)
		{
			printf("rb\n");
			rb(st);
		}
		else if (min == 6)
		{
			printf("sb\nrrb\n");
			sb(st);
			rrb(st);
		}
	}
	else
	{
		if (st->b[ind_b(st, 0)] > st->b[ind_b(st, 1)])
		{
			printf("sb\n");
			sb(st);
		}
	}
}
