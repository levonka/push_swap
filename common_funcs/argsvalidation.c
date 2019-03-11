/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argsvalidation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:22:40 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/04 15:42:14 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	iscopy(t_st *st)
{
	int		i;
	int		j;

	i = 0;
	while (i < st->a_size)
	{
		j = i + 1;
		while (j < st->a_size)
		{
			if (st->a[i] == st->a[j])
				printerror(43);
			j++;
		}
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

int			argsvalidation(int ac, char **av, t_st *st)
{
	int		i;
	int		j;
	char	*part;
	int		flag;

	i = 1;
	j = 0;
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
