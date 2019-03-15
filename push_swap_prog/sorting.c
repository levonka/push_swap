#include "../inc/push_swap.h"

int		partition(t_st *st, int size, char stack)
{
	int i;
	int j;
	int pivot;

	i = 0;
	j = 0;
	pivot = getmedian(st, size, stack);
	printf("pivot = %d\n", pivot);
	while (i < size)
	{
		if (st->a[ind_a(st, 0)] <= pivot)
		{
			pb(st, 1);
			j++;
		}
		else
			ra(st, 1);
		i++;
	}
	return(size - j);
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

void	sorting(t_st *st, int size, char stack)
{
	int		pindex;

	if (size <= 3)
	{
		if (stack == 'a')
		{
			sortthree_a(st, size);
			print_tab(st);
		}
		else
		{
			sortthree_b(st, size);
			print_tab(st);
			toa(st, size);
			print_tab(st);
		}
	}
	else
	{
		pindex = partition(st, size, stack);
		sorting(st, size - pindex, 'a');
		sorting(st, size - pindex, 'b');
	}
}