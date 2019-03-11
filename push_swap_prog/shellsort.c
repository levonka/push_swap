/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:11:31 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/07 16:38:37 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	shellsort(int *tab, unsigned size)
{
	unsigned	i;
	unsigned	j;
	unsigned	d;
	int			key;

	d = size / 2;
	while (d > 0)
	{
		i = d;
		while (i < size)
		{
			key = tab[i];
			j = i;
			while (j >= d && key < tab[j - d])
			{
				tab[j] = tab[j - d];
				j -= d;
			}
			tab[j] = key;
			i++;
		}
		d /= 2;
	}
}
