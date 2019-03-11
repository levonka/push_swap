/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_returners.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:34:33 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/08 08:44:20 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		ind_a(t_st *st, int n)
{
	if (st->a_top + n < st->end + 1 && n >= 0)
		return (st->a_top + n);
	if (n < 0)
	{
		if (st->a_top + n >= 0)
			return (st->a_top + n);
		else
			return (st->end);
	}
	else
		return ((st->a_top + n) % (st->end + 1));
	return (0);
}

int		ind_b(t_st *st, int n)
{
	if (st->b_top + n < st->end + 1 && n >= 0)
		return (st->b_top + n);
	if (n < 0)
	{
		if (st->b_top + n >= 0)
			return (st->b_top + n);
		else
			return (st->end);
	}
	else
		return ((st->b_top + n) % (st->end + 1));
	return (0);
}
