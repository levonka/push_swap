#include "../inc/push_swap.h"

int test5 = 0;

static void	sort_small_part(t_st *st, int size, char stack)
{
	if (stack == 'a')
		sortthree_a(st, size);
	else
		sortthree_b(st, size);
	if (test5 == 1)
		print_tab(st);
}

void		sorting(t_st *st, int size, char stack, int b)
{
	int		pindex;

	if (size <= 3)
		sort_small_part(st, size, stack);
	else
	{
		if (stack == 'a')
		{
			pindex = partition_a(st, size, b, -1);
			sorting(st, pindex, 'a', b + 1);
			sorting(st, size - pindex, 'b', b + 1);
		}
		else
		{
			pindex = partition_b(st, size, stack);
			sorting(st, size - pindex, 'a', b + 1);
			sorting(st, pindex, 'b', b + 1);
		}
		if (test5 == 1)
			print_tab(st);
	}
	if (b == 0)
		st->instr[st->instr_end] = '\0';
}
