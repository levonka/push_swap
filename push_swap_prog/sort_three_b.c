/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:08:46 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/20 17:09:45 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
**	minimal_ind_b return cases:
**	1 - 3 2 1
**	2 - 3 1 2
**	3 - 2 3 1
**	4 - 2 1 3
**	5 - 1 3 2
**	6 - 1 2 3
*/

static int	minimal_ind_b(t_st *st)
{
	if (st->b[ind_b(st, 0)] > st->b[ind_b(st, 1)] &&
		st->b[ind_b(st, 1)] > st->b[ind_b(st, 2)] &&
		st->b[ind_b(st, 0)] > st->b[ind_b(st, 2)])
		return (1);
	else if (st->b[ind_b(st, 0)] > st->b[ind_b(st, 1)] &&
		st->b[ind_b(st, 0)] > st->b[ind_b(st, 2)])
		return (2);
	else if (st->b[ind_b(st, 0)] < st->b[ind_b(st, 1)] &&
		st->b[ind_b(st, 0)] > st->b[ind_b(st, 2)])
		return (3);
	else if (st->b[ind_b(st, 0)] > st->b[ind_b(st, 1)] &&
		st->b[ind_b(st, 0)] < st->b[ind_b(st, 2)])
		return (4);
	else if (st->b[ind_b(st, 0)] < st->b[ind_b(st, 1)] &&
		st->b[ind_b(st, 1)] > st->b[ind_b(st, 2)])
		return (5);
	else if (st->b[ind_b(st, 0)] < st->b[ind_b(st, 1)] &&
		st->b[ind_b(st, 1)] < st->b[ind_b(st, 2)])
		return (6);
	return (0);
}

static void	sortthree_b_m(t_st *st, int min)
{
	if (min == 4)
	{
		pa(st, 1);
		sb(st, 1);
		pa(st, 1);
		sa(st, 1);
		pa(st, 1);
	}
	else if (min == 5)
	{
		sb(st, 1);
		pa(st, 1);
		sb(st, 1);
		pa(st, 1);
		pa(st, 1);
	}
	else if (min == 6)
	{
		rb(st, 1);
		sb(st, 1);
		pa(st, 1);
		pa(st, 1);
		rrb(st, 1);
		pa(st, 1);
	}
}

static void	ifsize_3_b(int min, int size, t_st *st)
{
	if (min == 2)
	{
		pa(st, 1);
		sb(st, 1);
		pa(st, 1);
		pa(st, 1);
	}
	else if (min == 3)
		sb(st, 1);
	else if (min == 4)
		rrb(st, 1);
	else if (min == 5)
		rb(st, 1);
	else if (min == 6)
	{
		sb(st, 1);
		rrb(st, 1);
	}
	while (size > 0 && min != 2)
	{
		pa(st, 1);
		size--;
	}
}

void		sortthree_b(t_st *st, int size)
{
	int		min;

	min = minimal_ind_b(st);
	if (st->b_size > size && size != 2 && min > 3)
		sortthree_b_m(st, min);
	else if (size == 3)
		ifsize_3_b(min, size, st);
	else
	{
		if (st->b[ind_b(st, 0)] < st->b[ind_b(st, 1)])
			sb(st, 1);
		pa(st, 1);
		pa(st, 1);
	}
}
