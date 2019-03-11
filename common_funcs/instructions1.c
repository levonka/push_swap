/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:14:38 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/04 15:33:11 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_st *st)
{
	if (st->a_size > 1)
		ft_swapint(&st->a[st->a_top], &st->a[ind_a(st, 1)]);
}

void	sb(t_st *st)
{
	if (st->b_size > 1)
		ft_swapint(&st->b[st->b_top], &st->b[ind_b(st, 1)]);
}

void	ss(t_st *st)
{
	sa(st);
	sb(st);
}

void	pa(t_st *st)
{
	if (st->b_size > 0)
	{
		st->a[ind_a(st, -1)] = st->b[st->b_top];
		st->a_size++;
		st->a_top = ind_a(st, -1);
		st->b_size--;
		st->b_top = ind_b(st, 1);
	}
}

void	pb(t_st *st)
{
	if (st->a_size > 0)
	{
		st->b[ind_b(st, -1)] = st->a[st->a_top];
		st->b_size++;
		st->b_top = ind_b(st, -1);
		st->a_size--;
		st->a_top = ind_a(st, 1);
	}
}
