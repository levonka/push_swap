#include "../inc/push_swap.h"

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\v' || c == '\n' || \
		c == '\f' || c == '\t' || c == '\r')
		return (1);
	return (0);
}

void	empty_valid(const char *str, int *sign, int *i)
{
	while (ft_isspace(str[*i]) == 1)
		(*i)++;
	(str[*i] == '-') ? *sign *= -1 : *sign;
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
	if (*i == (int)ft_strlen(str))
		printerror(44);
}

int		ft_vatoi(const char *str, int i)
{
	unsigned long	res;
	int				sign;

	res = 0;
	sign = 1;
	empty_valid(str, &sign, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - 48;
		if (ft_isdigit(str[++i]) == 0 && str[i] != '\0')
			printerror(41);
	}
	if (ft_isdigit(str[i]) == 0 && str[i] != '\0')
			printerror(41);
	if ((res > 2147483647 && sign == 1) || (res > 2147483648 && sign == -1))
		printerror(42);
	return ((int)res * sign);
}

int		argvalidation(int ac, char **av)//, t_st *st)
{
	int		i;
	char	*part;

	i = 1;
	if (ac == 1)
		printerror(40);
	else
	{
		while (i < ac)
		{
			part = av[i];
			ft_vatoi(part, 0);
			i++;
		}
	}
	return (0);
}

