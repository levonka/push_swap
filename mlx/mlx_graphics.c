/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:37:13 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/22 13:49:43 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_mlx   init_mlx(void *mlx, int width, int height)
{
    t_mlx   mx;

    mx.mlx_init = mlx;
    mx.width = width;
    mx.height = height;
    return (mx);
}

void   init_win(t_mlx *mlx, char *title, int width, int height)
{
    mlx->title = title;
    mlx->win = mlx_new_window(mlx->mlx_init, mlx->width, mlx->height,
			mlx->title);
}