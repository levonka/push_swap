#include "../inc/push_swap.h"

static void	empty_argsamount(char **str, int *sign)
{
	while (ft_isspace(**str))
		(*str)++;
	(**str == '-') ? *sign *= -1 : *sign;
	if (**str == '-' || **str == '+')
		(*str)++;
}

static int	ft_amountatoi(char **str)
{
	unsigned long	res;
	int				sign;

	res = 0;
	sign = 1;
	empty_argsamount(str, &sign);
	while (**str >= '0' && **str <= '9')
	{
		res = (res * 10) + **str - 48;
		(*str)++;
		if (ft_isdigit(**str) == 0 && ft_isspace(**str) == 0 && **str != '\0')
			printerror(41);
	}
	if (ft_isdigit(**str) == 0 && ft_isspace(**str) == 0 && **str != '\0')
		printerror(41);
	if ((res > 2147483647 && sign == 1) || (res > 2147483648 && sign == -1))
		printerror(42);
	while (ft_isspace(**str))
		(*str)++;
	return ((int)res * sign);
}

int		argsamount(int ac, char **av)
{
	int		i;
	int		len;
	char	*part;
	int		flag = 1;

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

