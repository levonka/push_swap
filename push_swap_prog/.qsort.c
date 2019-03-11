#include <stdio.h>

void	tab_print(int *A, int start, int end)
{
	while (start <= end)
	{
		printf("%d ", A[start]);
		start++;
	}
	printf("\n");
}

void	swap_int(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		partition(int *A, int start, int end)
{
	int		pivot;
	int		pIndex;
	int		i;

	pivot = A[end];
	pIndex = start;
	i = start;
	while (i <= end - 1)
	{
		if (A[i] < pivot)
		{
			swap_int(&A[i], &A[pIndex]);
			pIndex++;
		}
		i++;
	}
	swap_int(&A[pIndex], &A[end]);
	return (pIndex);
}

void	quicksort(int *A, int start, int end)
{
	int		pIndex;

	if (start < end)
	{
		pIndex = partition(A, start, end);
		quicksort(A, start, pIndex - 1);
		quicksort(A, pIndex + 1, end);
	}
}

int		main(void)
{
	int		A[11] = { 1, 6, 0, 5, 3, 10, 2, 8, 9, 7, 4 };

	tab_print(A, 0, 10);
	quicksort(A, 0, 10);
	tab_print(A, 0, 10);
}