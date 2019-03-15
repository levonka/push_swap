/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:11:31 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/15 17:50:23 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		partition_hoare(int *arr, int start, int end)
{
	int	i;
	int	pivot;
	int j;

	pivot = arr[end];
	i = start;
	j = end - 1;
	while (1)
	{
		while (arr[i] < pivot)
		{
			i++;
		}
		while (arr[j] >= pivot)
		{
			j--;
			if (j <= i)
				break ;
		}
		if (i >= j)
			break ;
		ft_swapint(&arr[i], &arr[j]);
	}
	ft_swapint(&arr[end], &arr[i]);
	return (i);
}

void	quicksort(int *arr, int start, int end)
{
	int p_index;

	p_index = 0;
	if (start < end)
	{
		p_index = partition_hoare(arr, start, end);
		quicksort(arr, start, p_index - 1);
		quicksort(arr, p_index + 1, end);
	}
}
