#include "../inc/push_swap.h"

int test5 = 0;

int		getbegin(t_st *st, int pivot, int size, char stack)
{
    int		i;

    i = 0;
    if (stack == 'a')
        while (i < size)
        {
            if (st->a[ind_a(st, i)] > pivot)
                return (st->a[ind_a(st, i)]);
            i++;
        }
    else
        while (i < size)
        {
            if (st->b[ind_b(st, i)] > pivot)
                return (st->b[ind_b(st, i)]);
            i++;
        }
    return (st->b[ind_b(st, i)]);
}

int		partition_a(t_st *st, int size, char stack)
{
	int i;
	int j;
	int pivot;
	int amount;
	int begin;

	i = 0;
	j = 0;
	pivot = getmedian(st, size, &amount, stack);
    begin = getbegin(st, pivot, size, stack);
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
	if (test5 == 1)
    	print_tab(st);      // vot
//	if ((i - j) != j && begin != st->a[ind_a(st, 0)] && st->a_size == size) // DELETE SOME CONDITIONS
    if ((size - i) < (i - j) && (i - j) != j && begin != st->a[ind_a(st, 0)] && st->a_size == size / 2) // DELETE SOME CONDITIONS
		while (i < size)
		{
			ra(st, 1);
			i++;
		}
	else if (begin != st->a[ind_a(st, 0)])
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
	int begin;

	i = 0;
	j = 0;
	pivot = getmedian(st, size, &amount, stack);
    begin = getbegin(st, pivot, size, stack);
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
    if (test5 == 1)
        print_tab(st);      // vot
	if ((i - j) != j && begin != st->b[ind_b(st, 0)] && st->b_size == size) // DELETE SOME CONDITIONS
		while (i < size)
		{
			rb(st, 1);
			i++;
		}
	else if (begin != st->b[ind_b(st, 0)])
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
            if (test5 == 1)
			    print_tab(st);      // vot
		}
		else
		{
			sortthree_b(st, size);
            if (test5 == 1)
			    print_tab(st);      // vot
			toa(st, size);
            if (test5 == 1)
			    print_tab(st);      // vot
		}
	}
	else
	{
		if (stack == 'a')
		{
			pindex = partition_a(st, size, stack);
			if (test5 == 1)
	    		print_tab(st);      // vot
			sorting(st, pindex, 'a', b + 1);
			sorting(st, size - pindex, 'b', b + 1);
		}
		else
		{
			pindex = partition_b(st, size, stack);
            if (test5 == 1)
			    print_tab(st);      // vot
			sorting(st, size - pindex, 'a', b + 1);
			sorting(st, pindex, 'b', b + 1);
		}
		if (b == 0)
			sortthree_a(st, 3);
	}
}
