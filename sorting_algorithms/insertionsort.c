#include "../inc/push_swap.h"

void	insertionsort(int tab[], int size)
{
	int		i;
	int		j;
	int		key;

	i = 1;
	while (i < size)
	{
		key = tab[i];
		j = i - 1;
		while (j >= 0 && tab[j] > key)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = key;
		i++;
	}
}