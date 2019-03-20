/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 14:04:02 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/20 16:07:51 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*ft_ntoa_base(uintmax_t n, int base)
{
	static char			*nums = "0123456789abcdefghijklmnopqrstuvwxyzABCDEF";
	char				*res;
	unsigned long		len;

	res = NULL;
	len = ft_nlen(n, base);
	if (!(res = (char*)malloc(sizeof(char) * (len + 40))))
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	while (len && n)
	{
		res[len - 1] = nums[ft_abs(n % base)];
		n = n / base;
		len--;
	}
	return (res);
}

char		*octo_addzero(char *str)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_strnew(ft_strlen(str));
	new[0] = '0';
	while (str[i] != '\0')
	{
		new[i + 1] = str[i];
		i++;
	}
	new[i + 1] = '\0';
	return (new);
}

char		*expand_str(char *str)
{
	char	*exp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j] == ' ')
		j++;
	j != 1 ? j = 0 : 0;
	exp = ft_strnew(ft_strlen(str) + 2);
	exp[i++] = '0';
	exp[i++] = 'x';
	while (str[j] != '\0')
	{
		exp[i] = str[j];
		j++;
		i++;
	}
	exp[i] = '\0';
	return (exp);
}
