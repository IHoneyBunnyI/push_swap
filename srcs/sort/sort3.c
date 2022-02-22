#include "push_swap.h"

void	sort3(t_stacks *stacks)
{
	if (stacks->a->index > stacks->a->next->index)
		sa(stacks);
}
