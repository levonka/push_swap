/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 08:03:13 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/21 08:04:42 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	toa(t_st *st, int *amount, int pivot, int *j)
{
	if (st->b[ind_b(st, 0)] > pivot)
	{
		pa(st, 1);
		(*amount)--;
		(*j)++;
	}
	else
		rb(st, 1);
}

int			partition_b(t_st *st, int size, char stack)
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
		toa(st, &amount, pivot, &j);
		i++;
	}
	if (stepcounter(st, begin, size - j, stack) && begin != st->b[ind_b(st, 0)])
		while (i++ < size)
			rb(st, 1);
	else if (begin != st->b[ind_b(st, 0)])
		while ((i - j) > 0)
		{
			rrb(st, 1);
			i--;
		}
	return (size - j);
}
