/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_instruct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:21:10 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/21 08:57:20 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	instruction_number(char instr)
{
	if (instr == '1')
		ft_printf("sa\n");
	else if (instr == '2')
		ft_printf("sb\n");
	else if (instr == '3')
		ft_printf("ss\n");
	else if (instr == '4')
		ft_printf("pa\n");
	else if (instr == '5')
		ft_printf("pb\n");
	else if (instr == '6')
		ft_printf("ra\n");
	else if (instr == '7')
		ft_printf("rb\n");
	else if (instr == '8')
		ft_printf("rr\n");
	else if (instr == '9')
		ft_printf("rra\n");
	else if (instr == 'a')
		ft_printf("rrb\n");
	else if (instr == 'b')
		ft_printf("rrr\n");
}

void		print_instructions(t_st *st)
{
	int		i;

	i = 0;
	while (i < st->instr_end)
	{
		instruction_number(st->instr[i]);
		i++;
	}
}

void		malloc_instruction(int ac, t_st *st)
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
	else if (ac <= 1000)
		st->instr = malloc(sizeof(char) * 13000);
	else if (ac <= 5000)
		st->instr = malloc(sizeof(char) * 78000);
	else if (ac <= 7000)
		st->instr = malloc(sizeof(char) * 116000);
	else if (ac <= 10000)
		st->instr = malloc(sizeof(char) * 170000);
	else if (ac <= 15000)
		st->instr = malloc(sizeof(char) * 272000);
	else if (ac <= 19425)
		st->instr = malloc(sizeof(char) * 358000);
}
