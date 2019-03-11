/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:52:55 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/11 08:11:23 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/ft_printf.h"
#include <stdio.h>

/*
** __________________________ Structure Definition _____________________________
**
**	top		- pointer to the first element in the stacks (by index).
**	size	- amount of numbers in stacks.
**	end		- last index in stacks.
*/

typedef struct		s_st
{
	int				*a;
	int				*b;
	int				a_top;
	int				b_top;
	int				a_size;
	int				b_size;
	int				end;
}					t_st;

/*
** ____________________________ Common Functions _______________________________
**
**	1. useful_funcs.c
**	2. index_returners.c
**	3. instructions1.c
**	4. instructions2.c
**	5. instructions3.c
**	6. argsamount.c
**	7. argsvalidation.c
*/

void	printerror(int status);
void	diag(t_st *st);
void	malloc_stack(t_st *stacks, int ac);
void    print_tab(t_st *stacks);

int		ind_a(t_st *st, int n);
int		ind_b(t_st *st, int n);

void	sa(t_st *st);
void	sb(t_st *st);
void	ss(t_st *st);
void	pa(t_st *st);
void	pb(t_st *st);

void	ra(t_st *st);
void	rb(t_st *st);
void	rr(t_st *st);
void	rra(t_st *st);
void	rrb(t_st *st);

void	rrr(t_st *st);

int		argsamount(int ac, char **av);

int		argsvalidation(int ac, char **av, t_st *st);

/*
** ________________________________ Checker ____________________________________
**
**	1. instructvalidation.c
**	2. issorted.c
*/

void	instructvalidation(t_st *st);

void	issorted(t_st *st);

/*
** _______________________________ Push swap ___________________________________
*/

// shellsort.c
void	shellsort(int *tab, unsigned size);

// sorting.c
void	sorting(t_st *st, int size, char stack);

// getmedian.c
int		getmedian(t_st *st, int size, char status);

// sortthree.c
void	sortthree_a(t_st *st, int size);
void	sortthree_b(t_st *st, int size);

/*
** ______________________________ Error Number _________________________________
**
**	0 - no error.
**	3 - memmory does not allocated.
**
**	validation
**	40 - there are no arguments.
**	41 - some arguments are not integers.
**	42 - some arguments are bigger or lower than an integer.
**	43 - there are duplicates.
**	44 - there are empty argument.
**	5 - an instruction don’t exist and/or is incorrectly formatted.
*/




#endif
