/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:14:38 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/23 11:30:14 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_st *st, char status)
{
	if (st->a_size > 1)
		ft_swapint(&st->a[st->a_top], &st->a[ind_a(st, 1)]);
	(status == 1) ? put_inst(st, '1') : 0;
	(st->v_flag == 1) ? ft_printf("sa\n") : 0;
	(st->v_flag == 1) ? print_tab(st) : 0;
}

void	sb(t_st *st, char status)
{
	if (st->b_size > 1)
		ft_swapint(&st->b[st->b_top], &st->b[ind_b(st, 1)]);
	(status == 1) ? put_inst(st, '2') : 0;
	(st->v_flag == 1) ? ft_printf("sb\n") : 0;
	(st->v_flag == 1) ? print_tab(st) : 0;
}

void	ss(t_st *st, char status)
{
	sa(st, 0);
	sb(st, 0);
	(status == 1) ? put_inst(st, '3') : 0;
	(st->v_flag == 1) ? ft_printf("ss\n") : 0;
	(st->v_flag == 1) ? print_tab(st) : 0;
}

void	pa(t_st *st, char status)
{
	if (st->b_size > 0)
	{
		st->a[ind_a(st, -1)] = st->b[st->b_top];
		st->a_size++;
		st->a_top = ind_a(st, -1);
		st->b_size--;
		st->b_top = ind_b(st, 1);
		(status == 1) ? put_inst(st, '4') : 0;
		(st->v_flag == 1) ? ft_printf("pa\n") : 0;
		(st->v_flag == 1) ? print_tab(st) : 0;
	}
}

void	pb(t_st *st, char status)
{
	if (st->a_size > 0)
	{
		st->b[ind_b(st, -1)] = st->a[st->a_top];
		st->b_size++;
		st->b_top = ind_b(st, -1);
		st->a_size--;
		st->a_top = ind_a(st, 1);
		(status == 1) ? put_inst(st, '5') : 0;
		(st->v_flag == 1) ? ft_printf("pb\n") : 0;
		(st->v_flag == 1) ? print_tab(st) : 0;
	}
}
