/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:51:19 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/20 16:52:30 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	sasb_rrara(t_st *st, int *i)
{
	if (st->instr[*i] == '1' && st->instr[*i + 1] == '2')
	{
		hlop(st, 1, *i);
		st->instr[*i] = '3';
		*i -= 5;
	}
	else if (st->instr[*i] == '9' && st->instr[*i + 1] == '6')
	{
		hlop(st, 2, *i);
		*i -= 5;
	}
}

void	sarrasbrrb(t_st *st, int *i)
{
	if (*i + 3 < st->instr_end && st->instr[*i] == '1' &&
		st->instr[*i + 1] == '9' && st->instr[*i + 2] == '2' &&
		st->instr[*i + 3] == 'a')
	{
		st->instr[*i] = '3';
		*i += 1;
		hlop(st, 2, *i);
		st->instr[*i] = 'b';
		*i -= 5;
	}
}

void	rrbrra(t_st *st, int *i)
{
	if (*i + 4 < st->instr_end && st->instr[*i] == 'a' &&
		st->instr[*i + 3] == '9')
	{
		st->instr[*i] = 'c';
		st->instr[*i + 3] = 'b';
		*i -= 5;
	}
	else if (*i + 5 < st->instr_end && st->instr[*i] == 'a' &&
		st->instr[*i + 1] == '1' && st->instr[*i + 2] == '6' &&
		st->instr[*i + 3] == '1' && st->instr[*i + 4] == '9')
	{
		st->instr[*i] = 'c';
		st->instr[*i + 4] = 'b';
		*i -= 5;
	}
}

void	edit_instructions(t_st *st)
{
	int		i;

	i = 0;
	while (i + 1 < st->instr_end)
	{
		sasb_rrara(st, &i);
		sarrasbrrb(st, &i);
		rrbrra(st, &i);
		i++;
	}
}
