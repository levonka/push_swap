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
            if (st->b[ind_b(st, i)] <= pivot)
                return (st->b[ind_b(st, i)]);
            i++;
        }
    return (st->b[ind_b(st, i)]);
}

int     stepcounter(t_st *st, int begin, int size, char stack)
{
    int     i;

    i = 0;
    if (stack == 'a')
        while (i < st->a_size)
        {
            if (test5 == 1)
                printf("ind_a = %d, begin = %d\n", st->a[ind_a(st, i)], begin);
            if (st->a[ind_a(st, i)] == begin)
                break ;
            i++;
        }
    else
        while (i < st->b_size)
        {
            if (test5 == 1)
                printf("ind_b = %d, begin = %d\n", st->b[ind_b(st, i)], begin);
            if (st->b[ind_b(st, i)] == begin)
                break ;
            i++;
        }
    if (i > size / 2)
        return (0);
    return (1);
}

int		partition_a(t_st *st, int size, char stack, char deep)
{
	int i;
	int j;
	int pivot;
	int amount;
	int begin;
	static int first_loop;

	i = 0;
	j = 0;
//    printf("<first_loop = %d\n", first_loop);
	if (deep == first_loop || first_loop == 0)
        first_loop++;
	else if (deep != first_loop)
	    first_loop = -1;
//    printf(">first_loop = %d\n", first_loop);
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
    if (begin != st->a[ind_a(st, 0)] && stepcounter(st, begin, size - j, stack) && first_loop == -1)
    {
        while (i < size)
        {
            ra(st, 1);
            i++;
        }
    }
	else if (begin != st->a[ind_a(st, 0)] && first_loop == -1)
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
    if (stepcounter(st, begin, size - j, stack) && begin != st->b[ind_b(st, 0)])
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
			pindex = partition_a(st, size, stack, b);
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
	}
	if (b == 0)
		st->instr[st->instr_end] = '\0';
}
