#include "../inc/push_swap.h"

int		partition(t_st *st, int size, char stack)
{
	int i;
	int j;
	int pivot;

	pivot = getmedian(st, size, stack);
	// printf("pivot = %d\n", pivot);
	i = 0;
	j = 0;
	while (i < size)
	{
		if (st->a[ind_a(st, 0)] > pivot)
		{
			printf("pb\n");
			pb(st);
			j++;
		}
		else
		{
			printf("ra\n");
			ra(st);
		}
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
		pa(st);
		printf("pa\n");
		ra(st);
		printf("ra\n");
		i++;
	}
}

void	sorting(t_st *st, int size, char stack)
{
	int		pindex;

	print_tab(st);
	if (size <= 3)
	{
		if (stack == 'a')
			sortthree_a(st, size);
		else
		{
			sortthree_b(st, size);
			print_tab(st);
			toa(st, size);
		}
	}
	else
	{
		pindex = partition(st, size, stack);
		sorting(st, size - pindex, 'a');
		sorting(st, size - pindex, 'b');
	}
}
