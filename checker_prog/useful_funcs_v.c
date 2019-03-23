/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_funcs_v.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 08:46:39 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/23 08:47:22 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	malloc_instr_g(int ac, t_st *st)
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
