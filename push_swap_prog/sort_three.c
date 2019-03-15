#include "../inc/push_swap.h"

int		minimal_ind_a(t_st *st)
{
	if (st->a[ind_a(st, 0)] < st->a[ind_a(st, 1)] &&
		st->a[ind_a(st, 1)] < st->a[ind_a(st, 2)] &&
		st->a[ind_a(st, 0)] < st->a[ind_a(st, 2)])
		return (1);		// 1 2 3
	else if (st->a[ind_a(st, 0)] < st->a[ind_a(st, 1)] &&
		st->a[ind_a(st, 0)] < st->a[ind_a(st, 2)])
		return (2);		// 1 3 2
	else if (st->a[ind_a(st, 0)] > st->a[ind_a(st, 1)] &&
		st->a[ind_a(st, 0)] < st->a[ind_a(st, 2)])
		return (3);		// 2 1 3
	else if (st->a[ind_a(st, 0)] < st->a[ind_a(st, 1)] &&
		st->a[ind_a(st, 0)] > st->a[ind_a(st, 2)])
		return (4);		// 2 3 1
	else if (st->a[ind_a(st, 0)] > st->a[ind_a(st, 1)] &&
		st->a[ind_a(st, 1)] < st->a[ind_a(st, 2)])
		return (5);		// 3 1 2
	else if (st->a[ind_a(st, 0)] > st->a[ind_a(st, 1)] &&
		st->a[ind_a(st, 1)] > st->a[ind_a(st, 2)])
		return (6);		// 3 2 1
	return (0);
}

int		minimal_ind_b(t_st *st)
{
	if (st->b[ind_b(st, 0)] > st->b[ind_b(st, 1)] &&
        st->b[ind_b(st, 1)] > st->b[ind_b(st, 2)] &&
        st->b[ind_b(st, 0)] > st->b[ind_b(st, 2)])
		return (1);		// 3 2 1
	else if (st->b[ind_b(st, 0)] > st->b[ind_b(st, 1)] &&
		st->b[ind_b(st, 0)] > st->b[ind_b(st, 2)])
		return (2);		// 3 1 2
	else if (st->b[ind_b(st, 0)] < st->b[ind_b(st, 1)] &&
		st->b[ind_b(st, 0)] > st->b[ind_b(st, 2)])
		return (3);		// 2 3 1
	else if (st->b[ind_b(st, 0)] > st->b[ind_b(st, 1)] &&
		st->b[ind_b(st, 0)] < st->b[ind_b(st, 2)])
		return (4);		// 2 1 3
	else if (st->b[ind_b(st, 0)] < st->b[ind_b(st, 1)] &&
		st->b[ind_b(st, 1)] > st->b[ind_b(st, 2)])
		return (5);		// 1 3 2
	else if (st->b[ind_b(st, 0)] < st->b[ind_b(st, 1)] &&
		st->b[ind_b(st, 1)] < st->b[ind_b(st, 2)])
		return (6);		// 1 2 3
	return (0);
}

void		sortthree_a_m(t_st *st, int min)
{
	if (min == 4)
	{
		ra(st, 1);
		sa(st, 1);
		rra(st, 1);
		sa(st, 1);
	}
	else if (min == 5)
	{
		sa(st, 1);
		ra(st, 1);
		sa(st, 1);
		rra(st, 1);
	}
	else if (min == 6)
	{
		sa(st, 1);
		ra(st, 1);
		sa(st, 1);
		rra(st, 1);
		sa(st, 1);
	}
}

void		sortthree_a(t_st *st, int size)
{
	int		min;

	min = minimal_ind_a(st);
	if (st->a_size > size && size != 2 && min > 3)
		sortthree_a_m(st, min);
	else if (size == 3)
	{
		if (min == 2)
		{
			ra(st, 1);
			sa(st, 1);
			rra(st, 1);
		}
		else if (min == 3)
			sa(st, 1);
		else if (min == 4)
			rra(st, 1);
		else if (min == 5)
		{
			ra(st, 1);
		}
		else if (min == 6)
		{
			sa(st, 1);
			rra(st, 1);
		}
	}
	else
		if (st->a[ind_a(st, 0)] > st->a[ind_a(st, 1)])
			sa(st, 1);
}

void		sortthree_b_m(t_st *st, int min)
{
	if (min == 4)
	{
		rb(st, 1);
		sb(st, 1);
		rrb(st, 1);
		sb(st, 1);
	}
	else if (min == 5)
	{
		sb(st, 1);
		rb(st, 1);
		sb(st, 1);
		rrb(st, 1);
	}
	else if (min == 6)
	{
		sb(st, 1);
		rb(st, 1);
		sb(st, 1);
		rrb(st, 1);
		sb(st, 1);
	}
}

void		sortthree_b(t_st *st, int size)
{
	int		min;

	min = minimal_ind_b(st);
	if (st->b_size > size && size != 2 && min > 3)
		sortthree_b_m(st, min);
	else if (size == 3)
	{
		if (min == 2)
		{
			rb(st, 1);
			sb(st, 1);
			rrb(st, 1);
		}
		else if (min == 3)
			sb(st, 1);
		else if (min == 4)
			rrb(st, 1);
		else if (min == 5)
			rb(st, 1);
		else if (min == 6)
		{
			sb(st, 1);
			rrb(st, 1);
		}
	}
	else
		if (st->b[ind_b(st, 0)] < st->b[ind_b(st, 1)])
			sb(st, 1);
}
