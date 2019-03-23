/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:14:44 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/23 08:33:49 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	printerror(int status)
{
	ft_printf("Error\n");
	exit(status);
}

void	diag(t_st *st)
{
	ft_printf("\n");
	ft_printf("|%.3clr %3d|\t", "a_top =", st->a_top);
	ft_printf("|%.3clr %3d|\n", "a_size =", st->a_size);
	ft_printf("|%.2clr %3d|\t", "b_top =", st->b_top);
	ft_printf("|%.2clr %3d|\t", "b_size =", st->b_size);
	ft_printf("|%.1clr %3d|\n", "end =", st->end);
	ft_printf("\n");
}

void	malloc_stack(t_st *stacks, int ac)
{
	static char status;

	if (status == 0)
	{
		stacks->a = (int *)malloc(sizeof(int) * ac);
		stacks->b = (int *)malloc(sizeof(int) * ac);
		stacks->end = ac - 1;
		stacks->b_top = ac;
		stacks->b_size = 0;
		stacks->a_top = 0;
		stacks->a_size = ac;
		stacks->instr_end = 0;
		stacks->v_flag = 0;
		if (stacks == NULL || stacks->a == NULL || stacks->b == NULL)
			exit(3);
		status = 1;
	}
	else
	{
		free(stacks->a);
		free(stacks->b);
		free(stacks->instr);
		free(stacks);
		status = 0;
	}
}

void	print_tab(t_st *st)
{
	int		i;

	i = 0;
	ft_printf("%.3clr    %.2clr\n", "+ stack a +", "+ stack b +");
	while (i < st->a_size || i < st->b_size)
	{
		if (i < st->a_size)
			ft_printf("%.3clr%6d%4.3clr", "|", st->a[ind_a(st, i)], "|");
		else
			ft_printf("%-5.3clr-%5.3clr", "|", "|");
		if (i < st->b_size)
			ft_printf("%5.2clr%6d%4.2clr\n", "|", st->b[ind_b(st, i)], "|");
		else
			ft_printf("%5.2clr    -%5.2clr\n", "|", "|");
		i++;
	}
	ft_printf("%.3clr    %.2clr\n", "|_________|", "|_________|");
}

void	copytab(t_st *st, int *new_tab, int size, char status)
{
	int		i;

	i = 0;
	if (status == 'a')
		while (i < size)
		{
			new_tab[i] = st->a[ind_a(st, i)];
			i++;
		}
	else
		while (i < size)
		{
			new_tab[i] = st->b[ind_b(st, i)];
			i++;
		}
}
