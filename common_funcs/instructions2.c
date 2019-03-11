/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:32:04 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/04 15:32:39 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_st *st)
{
	if (st->a_size >= 2)
	{
		st->a[ind_a(st, st->a_size)] = st->a[st->a_top];
		st->a_top = ind_a(st, 1);
	}
}

void	rb(t_st *st)
{
	if (st->b_size >= 2)
	{
		st->b[ind_b(st, st->b_size)] = st->b[st->b_top];
		st->b_top = ind_b(st, 1);
	}
}

void	rr(t_st *st)
{
	ra(st);
	rb(st);
}

void	rra(t_st *st)
{
	if (st->a_size >= 2)
	{
		st->a[ind_a(st, -1)] = st->a[ind_a(st, st->a_size - 1)];
		st->a_top = ind_a(st, -1);
	}
}

void	rrb(t_st *st)
{
	if (st->b_size >= 2)
	{
		st->b[ind_b(st, -1)] = st->b[ind_b(st, st->b_size - 1)];
		st->b_top = ind_b(st, -1);
	}
}
