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
	malloc_instruction(ac, stacks);

	// if (test == 1)
	    // print_tab(stacks);
	sorting(stacks, stacks->a_size, 'a', 0);
    edit_instructions(stacks);
    print_instructions(stacks);
	if (test == 1)
	{
    	// print_tab(stacks);
    	printf("%s\n", stacks->instr);
	}

	malloc_stack(stacks, ac);
	return (0);
}
