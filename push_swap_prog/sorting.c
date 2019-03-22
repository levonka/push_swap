/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 10:09:08 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/22 10:09:33 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		sorting(t_st *st, int size, char stack, int b)
{
	int		pindex;

	if (size <= 3)
		if (stack == 'a')
			sortthree_a(st, size);
		else
			sortthree_b(st, size);
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
	}
	if (b == 0)
		st->instr[st->instr_end] = '\0';
}
