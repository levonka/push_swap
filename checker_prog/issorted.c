/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:14:41 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/21 08:57:32 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	issorted(t_st *st)
{
	int		i;

	i = 0;
	while (i < st->a_size)
	{
		if (st->a[ind_a(st, i)] > st->a[ind_a(st, i + 1)])
			break ;
		i++;
	}
	if (i == st->a_size - 1 || st->a_size == 1)
		ft_printf("%.4clr\n", "OK");
	else
		ft_printf("%.2clr\n", "KO");
}
