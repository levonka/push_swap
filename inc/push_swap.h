/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:52:55 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/01 15:16:55 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include <stdio.h>

/*
** ______________________________ Sorting ______________________________________
*/
// void	print_tab(int tab[], int size);
void	insertionsort(int str[], int size);
void	shellssort(int *tab, unsigned size);
void	practice(int *tab, unsigned size);

/*
** _________________________ Structure Definition ______________________________
*/

typedef struct		s_st
{
	int				*a;
	int				*b;
	int				a_top;		// указатель на первый элемент стэка a (по индексу).
	int				b_top;		// указатель на первый элемент стэка b (по индексу).
	int				a_size;		// кол-во чисел в стэке a.
	int				b_size;		// кол-во чисел в стэке b.
	int				end;
}					t_st;

/*
** ______________________________ Checker ______________________________________
*/


//		checker.c
int		ind_a(t_st *st, int n);
int		ind_b(t_st *st, int n);

//		useful_funcs.c
void	diag(t_st *st);
void	printerror(int status);
void    print_tab(t_st *stacks);
void	malloc_stack(t_st *stacks, int ac);
void	ft_swapint(int *a, int *b);

//		handle_instructions.c
void	handle_instructions(t_st *stacks);

/*
** |_______________________ Validating Functions ______________________________|
*/

int		argvalidation(int ac, char **av);

/*
** ____________________________ Error Number ___________________________________
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
**	45 - an instruction don’t exist and/or is incorrectly formatted.
**
*/




#endif
