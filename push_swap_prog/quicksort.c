/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:11:31 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/15 15:57:59 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// void	shellsort(int *tab, unsigned size)
// {
// 	unsigned	i;
// 	unsigned	j;
// 	unsigned	d;
// 	int			key;

// 	d = size / 2;
// 	while (d > 0)
// 	{
// 		i = d;
// 		while (i < size)
// 		{
// 			key = tab[i];
// 			j = i;
// 			while (j >= d && key < tab[j - d])
// 			{
// 				tab[j] = tab[j - d];
// 				j -= d;
// 			}
// 			tab[j] = key;
// 			i++;
// 		}
// 		d /= 2;
// 	}
// }

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
	return(i);
}


void	quicksort(int *arr, int start, int end)
{
	int pIndex;

	pIndex = 0;
	if (start < end)
	{
		pIndex = partition_hoare(arr, start, end);
		quicksort(arr, start, pIndex - 1);
		quicksort(arr, pIndex + 1, end);
	}
}