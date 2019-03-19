#include "../inc/push_swap.h"

void	hlop(t_st *st, int len, int i)
{
	int		j;
	int		k;

	j = 0;
	while (j < len)
	{
		k = i;
		while (k < st->instr_end)
		{
			st->instr[k] = st->instr[k + 1];
			k++;
		}
		j++;
	}
	st->instr_end -= len;
	st->instr[st->instr_end] = '\0';
}

void	sasb(t_st *st, int *i)
{
	if (st->instr[*i] == '1' && st->instr[*i + 1] == '2')
	{
		hlop(st, 1, *i);
		st->instr[*i] = '3';
		*i -= 5;
	}
}

void	rrara(t_st *st, int *i)
{
	if (st->instr[*i] == '9' && st->instr[*i + 1] == '6')
	{
		hlop(st, 2, *i);
		*i -= 5;
	}
}

void	edit_instructions(t_st *st)
{
	int		i;

	i = 0;
	while (i + 1 < st->instr_end)
	{
		sasb(st, &i);
		rrara(st, &i);
		i++;
	}
}
