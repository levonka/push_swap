#include "../inc/push_swap.h"

/*
**	This is an ugly version of the function. See another in the early commits.
*/

static void	tob(t_st *st, int *amount, int pivot, int *j)
{
	if (st->a[ind_a(st, 0)] <= pivot)
	{
		pb(st, 1);
		(*amount)--;
		(*j)++;
	}
	else
		ra(st, 1);
}

int		partition_a(t_st *st, int size, char deep, int i)
{
	int			j;
	int			pivot;
	int			amount;
	int			begin;
	static int	first_loop;

	j = 0;
	if (deep == first_loop || first_loop == 0)
		first_loop++;
	else if (deep != first_loop)
		first_loop = -1;
	pivot = getmedian(st, size, &amount, 'a');
	begin = getbegin(st, pivot, size, 'a');
	while (++i < size && amount > 0)
		tob(st, &amount, pivot, &j);
	if (begin != st->a[ind_a(st, 0)] && stepcounter(st, begin, size - j, 'a')
		&& first_loop == -1)
		while (i++ < size)
			ra(st, 1);
	else if (begin != st->a[ind_a(st, 0)] && first_loop == -1)
		while ((i-- - j) > 0)
			rra(st, 1);
	return (size - j);
}