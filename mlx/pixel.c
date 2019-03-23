/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 08:24:04 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/23 08:49:26 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_pixel		init_pixel(double x, double y, unsigned int color)
{
	t_pixel pix;

	pix.x = x;
	pix.y = y;
	pix.color = color;
	return (pix);
}
