/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:49:28 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/22 13:58:09 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 // ./fdf maps/10-2.fdf
// #include "../inc/push_swap.h"

// int key_press(int keycode, void *param)
// {
// 	t_fdf fdf;
// 	t_pixel p1;
// 	t_pixel p2;
// 	static int y;
// 	static int x;
// 	int i = 0;

// 	fdf = *(t_fdf*)param;
// 	while (i < (WIN_H / 10))
// 	{
// 		p1 = init_pixel(1, y, 0xAAA4FD);
// 		p2 = init_pixel(fdf.stack[x] * 35, y, 0xAAA4FD);
// 		draw_line(p1, p2, &fdf);
// 		draw_img(fdf.mlx.mlx_init, fdf.mlx.win, fdf.mlx.img);
// 		y += 1;
// 		i++;
// 	}
// 	y += 1;
// 	x += 1;
// 	return(0);
// }

// int main(int argc, char **argv)
// {
// 	t_fdf   fdf;
// 	int     width;
// 	int     height;
// 	t_pixel p1;
// 	t_pixel p2;

// 	fdf.stack[0] = 5;
// 	fdf.stack[1] = 1;
// 	fdf.stack[2] = 6;
// 	fdf.stack[3] = 2;
// 	fdf.stack[4] = 9;
// 	fdf.stack[5] = 7;
// 	fdf.stack[6] = 0;
// 	fdf.stack[7] = 3;
// 	fdf.stack[8] = 8;
// 	fdf.stack[9] = 4;

// 	fdf.mlx = init_mlx(mlx_init(), WIN_W, WIN_H);
// 	init_win(&fdf.mlx, "PushSwap", fdf.mlx.width, fdf.mlx.height);
// 	fdf.mlx.img = init_img(fdf.mlx.mlx_init, fdf.mlx.width, fdf.mlx.height);
// 	p1 = init_pixel(500, 1, 0xCCCCCC);
// 	p2 = init_pixel(500, 799, 0xCCCCCC);
// 	draw_line(p1, p2, &fdf);
// 	draw_img(fdf.mlx.mlx_init, fdf.mlx.win, fdf.mlx.img);
// 	mlx_hook(fdf.mlx.win, 2, 0, key_press, (void*)(&fdf));
// 	mlx_loop(fdf.mlx.mlx_init);
// }
