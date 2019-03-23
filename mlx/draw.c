/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:56:17 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/22 13:49:39 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	draw_line(t_pixel a, t_pixel b, t_fdf *fdf)
{
	t_pixel	delta;
	t_pixel	sign;
	t_pixel	cur;
	int		error[2];

	delta.x = ft_abs(b.x - a.x);
	delta.y = ft_abs(b.y - a.y);
	sign.x = a.x < b.x ? 1 : -1;
	sign.y = a.y < b.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = a;
	while (cur.x != b.x || cur.y != b.y)
	{
		put_pix_img(fdf->mlx.mlx_init, fdf, cur, a.color);
		//mlx_pixel_put(fdf->mlx.mlx_init, fdf->mlx.win, cur.x, cur.y, 0x00FFFFFF);
		if ((error[1] = error[0] << 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}