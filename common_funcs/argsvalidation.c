/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argsvalidation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:22:40 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/22 10:03:48 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	iscopy(t_st *st)
{
	int		new_tab[st->a_size];
	int		i;

	i = 0;
	copytab(st, new_tab, st->a_size, 'a');
	quicksort(new_tab, 0, st->a_size - 1);
	while (i + 1 < st->a_size)
	{
		if (new_tab[i] == new_tab[i + 1])
			printerror(43);
		i++;
	}
}

static void	empty_valid(char **str, int *sign)
{
	int		len;

	len = (int)ft_strlen(*str);
	while (ft_isspace(**str))
		(*str)++;
	(**str == '-') ? *sign *= -1 : *sign;
	if (**str == '-' || **str == '+')
		(*str)++;
	if (**str == '\0')
		printerror(44);
	if (ft_isdigit(**str) == 0 && ft_isspace(**str) == 1)
		printerror(41);
}

static int	ft_vatoi(char **str)
{
	unsigned long	res;
	int				sign;

	res = 0;
	sign = 1;
	if (ft_strstr(*str, "v"))
		printerror(41);
	empty_valid(str, &sign);
	while (**str >= '0' && **str <= '9' && **str != '\0')
	{
		res = (res * 10) + **str - 48;
		(*str)++;
	}
	if ((res > 2147483647 && sign == 1) || (res > 2147483648 && sign == -1))
		printerror(42);
	while (ft_isspace(**str))
		(*str)++;
	return ((int)res * sign);
}

void		flag_v(t_st *st, int *ac, char **av, int *i)
{
	st->v_flag = 1;
	st->end--;
	st->a_size--;
	st->b_top--;
	(*ac)--;
	(*av)++;
	(*av)++;
	if (!(**av))
		(*i)++;
}

int			argsvalidation(int ac, char **av, t_st *st)
{
	int		i;
	int		j;
	char	*part;
	int		flag;

	i = 1;
	j = 0;
	if (ft_strstr(av[i], "-v") != NULL)
		flag_v(st, &ac, &(av[i]), &i);
	while (j < ac)
	{
		part = av[i];
		flag = 1;
		while (flag == 1)
		{
			st->a[j] = ft_vatoi(&part);
			j++;
			if (*part == '\0')
				flag = 0;
		}
		i++;
	}
	iscopy(st);
	return (0);
}
