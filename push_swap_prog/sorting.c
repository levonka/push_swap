#include "../inc/push_swap.h"

int		partition_a(t_st *st, int size, char stack)
{
	int i;
	int j;
	int pivot;
	int amount;

	i = 0;
	j = 0;
	pivot = getmedian(st, size, &amount, stack);
	while (i < size && amount > 0)
	{
		if (st->a[ind_a(st, 0)] <= pivot)
		{
			pb(st, 1);
			amount--;
			j++;
		}
		else
			ra(st, 1);
		i++;
    }
	// print_tab(st);      // vot
//	if (i - j <= size / 2 && amount == 0)
//		while (i < size)
//		{
//			ra(st, 1);
//			i++;
//		}
//	else
		while ((i - j) > 0)
		{
			rra(st, 1);
			i--;
		}
	return (size - j);
}

int		partition_b(t_st *st, int size, char stack)
{
	int i;
	int j;
	int pivot;
	int amount;

	i = 0;
	j = 0;
	pivot = getmedian(st, size, &amount, stack);
	while (i < size && amount > 0)
	{
		if (st->b[ind_b(st, 0)] > pivot)
		{
			pa(st, 1);
			amount--;
			j++;
		}
		else
			rb(st, 1);
		i++;
	}
	// print_tab(st);      // vot
	while ((i - j) > 0)
	{
		rrb(st, 1);
		i--;
	}
	return (size - j);
}

void	toa(t_st *st, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		pa(st, 1);
		i++;
	}
}

void	sorting(t_st *st, int size, char stack, int b)
{
	int		pindex;

	if (size <= 3)
	{
		if (stack == 'a')
		{
			sortthree_a(st, size);
			// print_tab(st);      // vot
		}
		else
		{
			sortthree_b(st, size);
			// print_tab(st);      // vot
			toa(st, size);
			// print_tab(st);      // vot
		}
	}
	else
	{
		if (stack == 'a')
		{
			pindex = partition_a(st, size, stack);
			// print_tab(st);      // vot
			sorting(st, pindex, 'a', b + 1);
			sorting(st, size - pindex, 'b', b + 1);
		}
		else
		{
			pindex = partition_b(st, size, stack);
			// print_tab(st);      // vot
			sorting(st, size - pindex, 'a', b + 1);
			sorting(st, pindex, 'b', b + 1);
		}
		if (b == 0)
			sortthree_a(st, 3);
	}
}
