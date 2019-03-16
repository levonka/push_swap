#include "../inc/push_swap.h"

int			getmedian(t_st *st, int size, int *amount, char status)
{
	int		new_tab[size];
	int		len;

	if (size == 0)
		return (0);
	len = (size / 2 - 1);
//	len = (size % 2 == 1) ? len - 1 : len;
	if (status == 'a')
		copytab(st, new_tab, size, 'a');
	else
		copytab(st, new_tab, size, 'b');
    quicksort(new_tab, 0, size - 1);
    *amount = size - 1 - len;
    *amount = (size % 2 == 1 && status != 'b') ? *amount - 1 : *amount;
	return (new_tab[len]);
}