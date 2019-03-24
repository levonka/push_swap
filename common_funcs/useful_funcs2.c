/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_funcs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 11:16:25 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/24 11:48:08 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	put_inst(t_st *st, char instruction)
{
	st->instr[st->instr_end] = instruction;
	st->instr_end++;
}

int		issorted(t_st *st, char status)
{
	int		i;

	i = 0;
	while (i < st->a_size)
	{
		if (st->a[ind_a(st, i)] > st->a[ind_a(st, i + 1)])
			break ;
		i++;
	}
	if ((i == st->a_size - 1 || st->a_size == 1) && st->b_size == 0)
	{
		(status == 1) ? ft_printf("%.4clr\n", "OK") : 0;
		return (1);
	}
	else
	{
		(status == 1) ? ft_printf("%.2clr\n", "KO") : 0;
		return (0);
	}
}
