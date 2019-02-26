#include "../inc/push_swap.h"

void    shellssort(int *tab, unsigned size)
{
	unsigned   i, j, d;
	int        key;

    d = size / 2;
	while (d > 0)
    {
        i = d;
        while (i < size)
        {
            key = tab[i];
            j = i;
            while (j >= d && key < tab[j - d])
            {
                tab[j] = tab[j - d];
                j -= d;
            }
            tab[j] = key;
            i++;
        }
        d /= 2;
    }
}
