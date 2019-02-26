#include "inc/push_swap.h"

void	print_tab(int tab[], int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
}

int		main(void)
{
	int		size = 10;
	int		tab[10] = {5, 1, 7, 0, 9, 4, 2, 3, 6, 8};

	print_tab(tab, size);
	// insertionsort(tab, size);
	// shellssort(tab, size);
	practice(tab, size);
	print_tab(tab, size);
	return (0);
}