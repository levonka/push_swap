/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:52:55 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/23 08:13:16 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/ft_printf.h"

/*
** __________________________ Structure Definition _____________________________
**
**	top			- pointer to the first element in the stacks (by index).
**	size		- amount of numbers in stacks.
**	end			- last index in stacks.
**	instr		- list of instructions.
**	instr_end	- pointer to the end of instr array.
*/

typedef struct	s_st
{
	int			*a;
	int			*b;
	int			a_top;
	int			b_top;
	int			a_size;
	int			b_size;
	int			end;
	char		*instr;
	int			instr_end;
	char		v_flag:2;
}				t_st;

// edit
# ifndef WIN_W
# define WIN_W 800
# endif

# ifndef WIN_H
#  define WIN_H 600
# endif

typedef struct      s_img
{
    void            *img;
    unsigned int    *data;
    int             size_line;
    int             end;
    int             bits_per_pixel;
    int             width;
    int             height;
}                   t_img;

typedef struct  s_mlx
{
    void        *mlx_init;
    int         width; // window width
    int         height; // window height
    char        *title;
    t_img       img;
    void        *win;
}               t_mlx;

typedef struct  s_fdf
{
    t_mlx       mlx;
    t_st        *st;
    int         max_del;
    int         stacks_size;
}               t_fdf;

typedef struct		  	s_pixel
{
    double				x;
    double				y;
    unsigned int		color;
}              			t_pixel;

// mlx
#include "mlx.h"
#include <fcntl.h>
#include <stdlib.h>
t_img   init_img(void *mlx, int width, int height);
int     draw_img(void *mlx, void *win, t_img img);
int     put_pix_img(void *mlx, void *mx, t_pixel p, unsigned int color);
void    draw_line(t_pixel a, t_pixel b, t_fdf *fdf);
t_mlx   init_mlx(void *mlx, int width, int height);
void    init_win(t_mlx *mlx, char *title, int width, int height);
t_pixel init_pixel(double x, double y, unsigned int color);
void    visualisation(t_st *st);

/*
** ____________________________ Common Functions _______________________________
**
**	1. useful_funcs.c
**	2. useful_funcs2.c
**	3. index_returners.c
**	4. instructions1.c
**	5. instructions2.c
**	6. instructions3.c
**	7. argsamount.c
**	8. argsvalidation.c
*/

void			printerror(int status);
void			diag(t_st *st);
void			malloc_stack(t_st *stacks, int ac);
void			print_tab(t_st *stacks);
void			copytab(t_st *st, int *new_tab, int size, char status);

void			put_inst(t_st *st, char instruction);

int				ind_a(t_st *st, int n);
int				ind_b(t_st *st, int n);

void			sa(t_st *st, char status);
void			sb(t_st *st, char status);
void			ss(t_st *st, char status);
void			pa(t_st *st, char status);
void			pb(t_st *st, char status);

void			ra(t_st *st, char status);
void			rb(t_st *st, char status);
void			rr(t_st *st, char status);
void			rra(t_st *st, char status);
void			rrb(t_st *st, char status);

void			rrr(t_st *st, char status);

int				argsamount(int ac, char **av);

int				argsvalidation(int ac, char **av, t_st *st);

/*
** ________________________________ Checker ____________________________________
**
**	1. instructvalidation.c
**	2. issorted.c
*/

void			instructvalidation(t_st *st);

void			issorted(t_st *st);

/*
** _______________________________ Push swap ___________________________________
**
**	1. quicksort.c
**	2. sorting.c
**	3. partititon_a.c
**	4. partititon_b.c
**	5. partititon_funcs.c
**	6. sortthree_a.c
**	7. sortthree_b.c
**	8. malloc_instruction.c
**	9. edit_instructions
*/

void			quicksort(int *arr, int start, int end);

void			sorting(t_st *st, int size, char stack, int b);

int				partition_a(t_st *st, int size, char deep, int i);

int				partition_b(t_st *st, int size, char stack);

int				getmedian(t_st *st, int size, int *amount, char status);
int				getbegin(t_st *st, int pivot, int size, char stack);
int				stepcounter(t_st *st, int begin, int size, char stack);

void			sortthree_a(t_st *st, int size);

void			sortthree_b(t_st *st, int size);

void			malloc_instruction(int ac, t_st *st);
void			print_instructions(t_st *st);

void			edit_instructions(t_st *st);

/*
** ______________________________ Error Number _________________________________
**
**	0  - no error.
**	3  - memmory does not allocated.
**
**	validation
**	40 - there are no arguments.
**	41 - some arguments are not integers.
**	42 - some arguments are bigger or lower than an integer.
**	43 - there are duplicates.
**	44 - there are empty argument.
**	5  - an instruction don’t exist and/or is incorrectly formatted.
**
**  6  - error in get_next_line.
**  7  - exit from -v flag.
*/

#endif
