#include "../inc/push_swap.h"

void	edit_instructions(t_st *st)
{
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(st->instr);
	while (i + 1 < size)
	{
		if (st->instr[i] == '1' && st->instr[i + 1] == '2')
		{
			st->instr[i] = '3';
			st->instr[i + 1] = 'c';
		}
		i++;
	}
}