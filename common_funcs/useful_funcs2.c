#include "../inc/push_swap.h"

void	put_inst(t_st *st, char instruction)
{
	st->instr[st->instr_end] = instruction;
	st->instr_end++;
}
