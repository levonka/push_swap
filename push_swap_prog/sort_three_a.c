/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:07:48 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/20 17:09:50 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
**	minimal_ind_a return cases:
**	1 - 1 2 3
**	2 - 1 3 2
**	3 - 2 1 3
**	4 - 2 3 1
**	5 - 3 1 2
**	6 - 3 2 1
*/

static int	minimal_ind_a(t_st *st)
{
	if (st->a[ind_a(st, 0)] < st->a[ind_a(st, 1)] &&
		st->a[ind_a(st, 1)] < st->a[ind_a(st, 2)] &&
		st->a[ind_a(st, 0)] < st->a[ind_a(st, 2)])
		return (1);
	else if (st->a[ind_a(st, 0)] < st->a[ind_a(st, 1)] &&
		st->a[ind_a(st, 0)] < st->a[ind_a(st, 2)])
		return (2);
	else if (st->a[ind_a(st, 0)] > st->a[ind_a(st, 1)] &&
		st->a[ind_a(st, 0)] < st->a[ind_a(st, 2)])
		return (3);
	else if (st->a[ind_a(st, 0)] < st->a[ind_a(st, 1)] &&
		st->a[ind_a(st, 0)] > st->a[ind_a(st, 2)])
		return (4);
	else if (st->a[ind_a(st, 0)] > st->a[ind_a(st, 1)] &&
		st->a[ind_a(st, 1)] < st->a[ind_a(st, 2)])
		return (5);
	else if (st->a[ind_a(st, 0)] > st->a[ind_a(st, 1)] &&
		st->a[ind_a(st, 1)] > st->a[ind_a(st, 2)])
		return (6);
	return (0);
}

static void	sortthree_a_m(t_st *st, int min)
{
	if (min == 4)
	{
		ra(st, 1);
		sa(st, 1);
		rra(st, 1);
		sa(st, 1);
	}
	else if (min == 5)
	{
		sa(st, 1);
		ra(st, 1);
		sa(st, 1);
		rra(st, 1);
	}
	else if (min == 6)
	{
		sa(st, 1);
		ra(st, 1);
		sa(st, 1);
		rra(st, 1);
		sa(st, 1);
	}
}

static void	ifsize_3_a(int min, t_st *st)
{
	if (min == 2)
	{
		ra(st, 1);
		sa(st, 1);
		rra(st, 1);
	}
	else if (min == 3)
		sa(st, 1);
	else if (min == 4)
		rra(st, 1);
	else if (min == 5)
		ra(st, 1);
	else if (min == 6)
	{
		sa(st, 1);
		rra(st, 1);
	}
}

void		sortthree_a(t_st *st, int size)
{
	int		min;

	min = minimal_ind_a(st);
	if (st->a_size > size && size != 2 && min > 3)
		sortthree_a_m(st, min);
	else if (size == 3)
		ifsize_3_a(min, st);
	else
	{
		if (st->a[ind_a(st, 0)] > st->a[ind_a(st, 1)])
			sa(st, 1);
	}
}
