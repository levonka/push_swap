/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:32:04 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/21 11:34:51 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_st *st, char status)
{
	if (st->a_size >= 2)
	{
		st->a[ind_a(st, st->a_size)] = st->a[st->a_top];
		st->a_top = ind_a(st, 1);
		(status == 1) ? put_inst(st, '6') : 0;
		(st->v_flag == 1) ? ft_printf("ra\n") : 0;
		(st->v_flag == 1) ? print_tab(st) : 0;
	}
}

void	rb(t_st *st, char status)
{
	if (st->b_size >= 2)
	{
		st->b[ind_b(st, st->b_size)] = st->b[st->b_top];
		st->b_top = ind_b(st, 1);
		(status == 1) ? put_inst(st, '7') : 0;
		(st->v_flag == 1) ? ft_printf("rb\n") : 0;
		(st->v_flag == 1) ? print_tab(st) : 0;
	}
}

void	rr(t_st *st, char status)
{
	ra(st, 0);
	rb(st, 0);
	(status == 1) ? put_inst(st, '8') : 0;
	(st->v_flag == 1) ? ft_printf("rr\n") : 0;
	(st->v_flag == 1) ? print_tab(st) : 0;
}

void	rra(t_st *st, char status)
{
	if (st->a_size >= 2)
	{
		st->a[ind_a(st, -1)] = st->a[ind_a(st, st->a_size - 1)];
		st->a_top = ind_a(st, -1);
		(status == 1) ? put_inst(st, '9') : 0;
		(st->v_flag == 1) ? ft_printf("rra\n") : 0;
		(st->v_flag == 1) ? print_tab(st) : 0;
	}
}

void	rrb(t_st *st, char status)
{
	if (st->b_size >= 2)
	{
		st->b[ind_b(st, -1)] = st->b[ind_b(st, st->b_size - 1)];
		st->b_top = ind_b(st, -1);
		(status == 1) ? put_inst(st, 'a') : 0;
		(st->v_flag == 1) ? ft_printf("rrb\n") : 0;
		(st->v_flag == 1) ? print_tab(st) : 0;
	}
}
