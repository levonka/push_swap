/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructvalidation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:14:39 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/21 09:17:46 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	do_instruct(char ind, t_st *st)
{
	if (ind == 0)
		sa(st, 0);
	else if (ind == 1)
		sb(st, 0);
	else if (ind == 2)
		ss(st, 0);
	else if (ind == 3)
		pa(st, 0);
	else if (ind == 4)
		pb(st, 0);
	else if (ind == 5)
		ra(st, 0);
	else if (ind == 6)
		rb(st, 0);
	else if (ind == 7)
		rr(st, 0);
	else if (ind == 8)
		rra(st, 0);
	else if (ind == 9)
		rrb(st, 0);
	else if (ind == 10)
		rrr(st, 0);
}

void		instructvalidation(t_st *st)
{
	const char	base[][4] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
	"rra", "rrb", "rrr", ""};
	char		*line;
	char		flag;
	int			i;

	st->instr = malloc(sizeof(char) * 1);
	while (get_next_line(0, &line))
	{
		i = 0;
		flag = 0;
		while (ft_strcmp(base[i], "") != 0)
		{
			if (ft_strcmp(line, base[i]) == 0)
			{
				do_instruct(i, st);
				flag = 1;
				break ;
			}
			i++;
		}
		if (flag == 0)
		{
			ft_printf(">>voooot\n");
			ft_printf(">>%s", line);
			printerror(5);
		}
		free(line);
	}
}
