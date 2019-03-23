#include "../inc/push_swap.h"

void	max_del(t_fdf *fdf)
{
	int		i;
	int		max;

	i = 0;
	max = fdf->st->a[ind_a(fdf->st, i)];
	while (i < fdf->st->a_size)
	{
		if (fdf->st->a[ind_a(fdf->st, i)] > max)
			max = fdf->st->a[ind_a(fdf->st, i)];
		i++;
	}
	fdf->max_del = (WIN_W / 2) / max;
}

void	draw_b(t_fdf fdf, int i, int j, int k)
{
	int		y;
	t_pixel	p1;
	t_pixel	p2;

	y = 0;
	while (j < fdf.st->b_size)
	{
		i = 0;
		while (i < ((WIN_H - fdf.stacks_size) / (fdf.stacks_size)))
		{
			p1 = init_pixel((WIN_W / 2) + 2, y, 0xFFAE72);
			p2 = init_pixel((WIN_W / 2) + 2 +
		ft_abs((fdf.st->b[ind_b(fdf.st, k)] * fdf.max_del - 2)), y, 0xFFAE72);
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
		while (i < ((WIN_H - fdf.stacks_size) / (fdf.stacks_size)))
		{
			p1 = init_pixel(1, y, 0xAAA4FD);
			p2 = init_pixel(ft_abs((fdf.st->a[ind_a(fdf.st, k)] *
		fdf.max_del - 2)), y, 0xAAA4FD);
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

void	do_instruct_g(t_fdf fdf, char i)
{
	if (i == '1')
		sa(fdf.st, 0);
	else if (i == '2')
		sb(fdf.st, 0);
	else if (i == '3')
		ss(fdf.st, 0);
	else if (i == '4')
		pa(fdf.st, 0);
	else if (i == '5')
		pb(fdf.st, 0);
	else if (i == '6')
		ra(fdf.st, 0);
	else if (i == '7')
		rb(fdf.st, 0);
	else if (i == '8')
		rr(fdf.st, 0);
	else if (i == '9')
		rra(fdf.st, 0);
	else if (i == 'a')
		rrb(fdf.st, 0);
	else if (i == 'b')
		rrr(fdf.st, 0);
}

int		key_press(int keycode, void *param)
{
	t_fdf		fdf;
	static int	i;
	t_pixel		p1;
	t_pixel		p2;

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

void		malloc_instr_g(int ac, t_st *st)
{
	if (ac < 50)
		st->instr = malloc(sizeof(char) * 400);
	else if (ac <= 100)
		st->instr = malloc(sizeof(char) * 800);
	else if (ac <= 150)
		st->instr = malloc(sizeof(char) * 1300);
	else if (ac <= 250)
		st->instr = malloc(sizeof(char) * 2400);
	else if (ac <= 500)
		st->instr = malloc(sizeof(char) * 5500);
	else if (ac >= 501)
		st->instr = malloc(sizeof(char) * 13000);
}

char	instr_return(int i)
{
	if (i == 0)
		return ('1');
	else if (i == 1)
		return ('2');
	else if (i == 2)
		return ('3');
	else if (i == 3)
		return ('4');
	else if (i == 3)
		return ('5');
	else if (i == 4)
		return ('5');
	else if (i == 5)
		return ('6');
	else if (i == 6)
		return ('7');
	else if (i == 7)
		return ('8');
	else if (i == 8)
		return ('9');
	else if (i == 9)
		return ('a');
	else if (i == 10)
		return ('b');
	return ('c');
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
	int		width;
	int		height;
	t_pixel	p1;
	t_pixel	p2;

	fdf.st = st;
	fdf.stacks_size = fdf.st->a_size;
	max_del(&fdf);
	read_instructions(fdf, 0, 0, 0);
	fdf.mlx = init_mlx(mlx_init(), WIN_W, WIN_H);
	init_win(&fdf.mlx, "PushSwap", fdf.mlx.width, fdf.mlx.height);
	fdf.mlx.img = init_img(fdf.mlx.mlx_init, fdf.mlx.width, fdf.mlx.height);
	p1 = init_pixel(WIN_W / 2, 1, 0xCCCCCC);
	p2 = init_pixel(WIN_W / 2, WIN_H - 1, 0xCCCCCC);
	draw_line(p1, p2, &fdf);
	draw_img(fdf.mlx.mlx_init, fdf.mlx.win, fdf.mlx.img);
	display_tab(fdf, 0, 0, 0);
	mlx_hook(fdf.mlx.win, 2, 0, key_press, (void*)(&fdf));
	mlx_loop(fdf.mlx.mlx_init);
}
