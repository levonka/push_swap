#include "../inc/push_swap.h"

int		partition_a(t_st *st, int size, char stack)
{
	int i;
	int j;
	int pivot;

	pivot = getmedian(st, size, stack);
	i = 0;
	j = 0;
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
	while ((i - j) > 0)
	{
		rra(st, 1);
		i--;
	}
	return(size - j);
}

int		partition_b(t_st *st, int size, char stack)
{
    int i;
    int j;
    int pivot;

    pivot = getmedian(st, size, stack);
    i = 0;
    j = 0;
    while (i < size)
    {
        if (st->b[ind_b(st, 0)] > pivot)
        {
            pa(st, 1);
            j++;
        }
        else
            rb(st, 1);
        i++;
    }
    while ((i - j) > 0)
    {
        rrb(st, 1);
        i--;
    }
    return(size - j);
}

void	tob(t_st *st, int size)
{
    int		i;

    i = 0;
    while (i < size)
    {
        pb(st, 1);
        i++;
    }
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
//			print_tab(st);      // vot
//			if (st->a_size != size)
//            if (b != 0)
//			{
//                tob(st, size);
//                print_tab(st);
//            }
		}
		else
		{
			sortthree_b(st, size);
//			print_tab(st);      // vot
			toa(st, size);
//			print_tab(st);      // vot
		}
	}
	else
	{
	    if (stack == 'a')
	    {
			pindex = partition_a(st, size, stack);
//			print_tab(st);      // vot
			sorting(st, pindex, 'a', b + 1);
			sorting(st, size - pindex, 'b', b + 1);
		}
	    else
		{
			pindex = partition_b(st, size, stack);
//			print_tab(st);      // vot
			sorting(st, size - pindex, 'a', b + 1);
			sorting(st, pindex, 'b', b + 1);
		}
		if (b == 0)
		{
            toa(st, st->b_size);
            sortthree_a(st, 3);
		}
	}
}
