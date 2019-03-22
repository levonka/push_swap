/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argsamount.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:18:31 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/21 10:56:28 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_amountatoi(char **str)
{
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '-' || **str == '+')
		(*str)++;
	while (**str >= '0' && **str <= '9' && **str != '\0')
		(*str)++;
	if (ft_isdigit(**str) == 0 && ft_isspace(**str) == 0 && **str != '\0' &&
		**str != 'v')
		printerror(41);
	if (**str == 'v')
		(*str)++;
	while (ft_isspace(**str))
		(*str)++;
}

int			argsamount(int ac, char **av)
{
	int		i;
	int		len;
	char	*part;
	int		flag;

	i = 1;
	len = 0;
	while (i < ac)
	{
		part = av[i];
		flag = 1;
		while (flag == 1)
		{
			ft_amountatoi(&part);
			len++;
			if (*part == '\0')
				flag = 0;
		}
		i++;
	}
	return (len);
}
