#include "../inc/push_swap.h"

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\v' || c == '\n' || \
		c == '\f' || c == '\t' || c == '\r')
		return (1);
	return (0);
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

static int		ft_vatoi(char **str)
{
	unsigned long	res;
	int				sign;

	res = 0;
	sign = 1;
	empty_valid(str, &sign);
	while (**str >= '0' && **str <= '9')
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

int		argvalidation(int ac, char **av, t_st *st)
{
	int		i;
	int		j;
	char	*part;
	int		flag = 1;

	i = 1;
	j = 0;
	if (ac == 1)
		printerror(40);
	else
		while (i < ac && j < ac)
		{
			part = av[i];
			flag = 1;
			while (flag == 1)
			{
				// printf(">> i = %d, j = %d\n", i, j);
				// printf("%s\n", part);
				st->a[j] = ft_vatoi(&part);
				j++;
				if (*part == '\0')
					flag = 0;
			}
			i++;
		}
	printf("valid\n");
	return (0);
}

