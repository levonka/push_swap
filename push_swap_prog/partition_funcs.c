/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:20:09 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/21 07:45:18 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		getbegin(t_st *st, int pivot, int size, char stack)
{
	int		i;

	i = 0;
	if (stack == 'a')
		while (i < size)
		{
			if (st->a[ind_a(st, i)] > pivot)
				return (st->a[ind_a(st, i)]);
			i++;
		}
	else
		while (i < size)
		{
			if (st->b[ind_b(st, i)] <= pivot)
				return (st->b[ind_b(st, i)]);
			i++;
		}
	return (st->b[ind_b(st, i)]);
}

int		stepcounter(t_st *st, int begin, int size, char stack)
{
	int		i;

	i = 0;
	if (stack == 'a')
		while (i < st->a_size)
		{
			if (st->a[ind_a(st, i)] == begin)
				break ;
			i++;
		}
	else
		while (i < st->b_size)
		{
			if (st->b[ind_b(st, i)] == begin)
				break ;
			i++;
		}
	if (i > size / 2)
		return (0);
	return (1);
}

int		getmedian(t_st *st, int size, int *amount, char status)
{
	int		new_tab[size];
	int		len;

	if (size == 0)
		return (0);
	len = (size / 2 - 1);
	if (status == 'a')
		copytab(st, new_tab, size, 'a');
	else
		copytab(st, new_tab, size, 'b');
	quicksort(new_tab, 0, size - 1);
	*amount = size - 1 - len;
	*amount = (size % 2 == 1 && status != 'b') ? *amount - 1 : *amount;
	return (new_tab[len]);
}
