/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:32:58 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/13 12:33:14 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rrr(t_st *st, char status)
{
	rra(st, 0);
	rrb(st, 0);
	(status == 1) ? ft_printf("rrr\n") : 0;
}
