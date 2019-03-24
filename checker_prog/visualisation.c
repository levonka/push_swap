/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 08:45:12 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/24 11:39:40 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	draw_b(t_fdf fdf, int i, int j, int k)
{
	int		y;
	t_pixel	p1;
	t_pixel	p2;

	y = 0;
	while (j < fdf.st->b_size)
	{
		i = 0;
		while (i < fdf.el_height)
		{
			p1 = init_pixel((WIN_W / 2) + 2, y, 0xEEDECB);
			p2 = init_pixel((WIN_W / 2) + 2 +
		ft_abs((fdf.st->b[ind_b(fdf.st, k)] * fdf.max_del - 2)), y, 0xA5514F);
			draw_line(p1, p2, &fdf);
			draw_img(fdf.mlx.mlx_init, fdf.mlx.win, fdf.mlx.img);
			y += 1;
			i++;
		}
		k++;
		j++;
		y++;
	}
}

void	display_tab(t_fdf fdf, int i, int j, int k)
{
	int		y;
	t_pixel	p1;
	t_pixel	p2;

	y = 0;
	while (j < fdf.st->a_size)
	{
		i = 0;
		while (i < fdf.el_height)
		{
			p1 = init_pixel(0, y, 0xA5514F);
			p2 = init_pixel(ft_abs((fdf.st->a[ind_a(fdf.st, k)] *
		fdf.max_del - 2)), y, 0xFFFFFF);
			draw_line(p1, p2, &fdf);
			draw_img(fdf.mlx.mlx_init, fdf.mlx.win, fdf.mlx.img);
			y += 1;
			i++;
		}
		k++;
		j++;
		y++;
	}
	draw_b(fdf, 0, 0, 0);
}

int		key_press(int keycode, void *param)
{
	t_fdf		fdf;
	static int	i;
	t_pixel		p1;
	t_pixel		p2;

	keycode = 1;
	fdf = *(t_fdf*)param;
	fdf.mlx.img = init_img(fdf.mlx.mlx_init, fdf.mlx.width, fdf.mlx.height);
	do_instruct_g(fdf, fdf.st->instr[i]);
	p1 = init_pixel(WIN_W / 2, 1, 0xCCCCCC);
	p2 = init_pixel(WIN_W / 2, WIN_H - 1, 0xCCCCCC);
	draw_line(p1, p2, &fdf);
	draw_img(fdf.mlx.mlx_init, fdf.mlx.win, fdf.mlx.img);
	display_tab(fdf, 0, 0, 0);
	mlx_destroy_image(fdf.mlx.mlx_init, fdf.mlx.img.img);
	i++;
	return (0);
}

void	read_instructions(t_fdf fdf, int i, int k, int flag)
{
	const char	base[][4] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
	"rra", "rrb", "rrr", ""};
	char		*line;

	malloc_instr_g(fdf.st->a_size, fdf.st);
	while (get_next_line(0, &line))
	{
		i = 0;
		flag = 0;
		while (base[i][0] != '\0')
		{
			if (ft_strcmp(line, base[i]) == 0)
			{
				fdf.st->instr[k] = instr_return(i);
				k++;
				flag = 1;
				break ;
			}
			i++;
		}
		if (flag == 0)
			printerror(5);
		free(line);
	}
	fdf.st->instr[k] = '\0';
}

void	visualisation(t_st *st)
{
	t_fdf	fdf;
	t_pixel	p1;
	t_pixel	p2;

	fdf.st = st;
	fdf.stacks_size = fdf.st->a_size;
	fdf.el_height = (WIN_H - fdf.stacks_size) / (fdf.stacks_size);
	max_del(&fdf);
	read_instructions(fdf, 0, 0, 0);
	fdf.mlx = init_mlx(mlx_init(), WIN_W, WIN_H);
	init_win(&fdf.mlx, "PushSwap");
	fdf.mlx.img = init_img(fdf.mlx.mlx_init, fdf.mlx.width, fdf.mlx.height);
	p1 = init_pixel(WIN_W / 2, 1, 0xCCCCCC);
	p2 = init_pixel(WIN_W / 2, WIN_H - 1, 0xCCCCCC);
	draw_line(p1, p2, &fdf);
	draw_img(fdf.mlx.mlx_init, fdf.mlx.win, fdf.mlx.img);
	display_tab(fdf, 0, 0, 0);
	mlx_hook(fdf.mlx.win, 2, 0, key_press, (void*)(&fdf));
	mlx_loop(fdf.mlx.mlx_init);
}
