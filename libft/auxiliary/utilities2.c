/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:23:17 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/20 16:08:49 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*add0x(char *str, int start, t_type *node)
{
	if (str[0] == '0' && str[1] == 'x')
		return (str);
	if ((str[start] == ' ' && str[start + 1] == ' ') ||
		(ft_strchr(node->flags, '0') && str[start] == '0' && str[start + 1]))
	{
		str[start] = '0';
		str[start + 1] = 'x';
		return (str);
	}
	else
		return (expand_str(str));
}

static char	*hashtag_mode_ext(char *str, t_type *node)
{
	if (str[0] == ' ' && str[1] == ' ')
	{
		str = shift_npos(str, 1);
		cmp(str, "0x") ? 0 : add0x(str, 0, node);
		return (add0x(str, 0, node));
	}
	else
	{
		if (str[0] == ' ')
			str = expand_str(str);
		if (node->precision < node->width)
		{
			if (ft_strchr(node->flags, '-'))
				str = shift_npos(str, 1);
			return (add0x(str, 0, node));
		}
		else
			return (expand_str(str));
	}
	return (str);
}

static char	*shift_npos_static(char *str, int n, int i, int j)
{
	while (n > 0)
	{
		while (str[i] != ' ')
			i++;
		j = i;
		while (i > 0 && str[i - 1] != ' ')
		{
			ft_swap(&str[i - 1], &str[i]);
			i--;
		}
		n--;
		i++;
	}
	return (str);
}

char		*shift_npos(char *str, int n)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str[i] == ' ' && str[i + 1] != ' ')
	{
		while (str[i] != '\0')
		{
			if (str[i + 1] == '\0')
				break ;
			ft_swap(&str[i], &str[i + 1]);
			i++;
		}
		str[i] = '\0';
		return (expand_str(str));
	}
	else
		str = shift_npos_static(str, n, i, j);
	return (str);
}

char		*hash(char *str, t_type *node, int i)
{
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	if (i < 3)
		return (hashtag_mode_ext(str, node));
	else
	{
		str[i - 2] = '0';
		str[i - 1] = 'x';
	}
	return (str);
}
