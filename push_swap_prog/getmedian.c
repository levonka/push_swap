#include "../inc/push_swap.h"

static void	copytab(t_st *st, int *new_tab, int size, char status)
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

int			getmedian(t_st *st, int size, char status)
{
	int		new_tab[size];
	int		len;

	if (size == 0)
		return (0);
	len = (size / 2 - 1);
	if (status == 'a')
		copytab(st, new_tab, size, 'a');
	else
		copytab(st, new_tab, size, 'b');
	quicksort(new_tab, 0, size - 1);
	return (new_tab[len]);
}
