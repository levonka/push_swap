/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:20:18 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/19 10:16:39 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** print_tab(stacks);
** diag(stacks);
*/

int test = 0;

int		main(int ac, char **av)
{
	t_st	*stacks;

	if (ac == 1)
		exit(40);
	stacks = (t_st *)malloc(sizeof(t_st));
	ac = argsamount(ac, av);
	malloc_stack(stacks, ac);
	argsvalidation(ac, av, stacks);

	if (test == 1)
	    print_tab(stacks);
//	diag(stacks);
//	tob(stacks, stacks->a_size, 0);
	sorting(stacks, stacks->a_size, 'a', 0);
	if (test == 1)
    	print_tab(stacks);
//	 diag(stacks);

	malloc_stack(stacks, ac);
	return (0);
}
