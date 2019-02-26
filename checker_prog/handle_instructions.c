#include "../inc/push_swap.h"

// void	pa(t_st *st)
// {
// 	if (st->b_top != 0)
// 	{
// 		st->a[st->a_top] = st->b[st->b_top - 1];
// 		st->a_top++;
// 		st->b_top--;
// 	}
// }

// void	pb(t_st *st)
// {
// 	if (st->a_top != 0)
// 	{
// 		st->b[st->b_top] = st->a[st->a_top - 1];
// 		st->b_top++;
// 		st->a_top--;
// 	}
// }

// void	sa(t_st *st)
// {
// 	int		tmp;

// 	if (st->a_top > 1)
// 	{
// 		tmp = st->a[st->a_top - 1];
// 		st->a[st->a_top - 1] = st->a[st->a_top - 2];
// 		st->a[st->a_top - 2] = tmp;
// 	}
// }

// void	handle_instructions(t_st *st)
// {
// 	ft_printf("%.clr\n", "========= SA =========");
// 	sa(st);
// 	print_tab(st);
// 	ft_printf("\n%.clr\n", "========= PB =========");
// 	pb(st);
// 	pb(st);
// 	pb(st);
// 	pb(st);
// 	print_tab(st);
// 	ft_printf("\n%.clr\n", "========= PA =========");
// 	pa(st);
// 	pa(st);
// 	print_tab(st);

// }