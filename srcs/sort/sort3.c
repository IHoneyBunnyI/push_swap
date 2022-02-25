#include "push_swap.h"

void	sort3(t_stacks *stacks)
{
	int i1;
	int i2;
	int i3;

	i1 = stacks->a->index;
	i2 = stacks->a->next->index;
	i3 = -1;
	if (stacks->size == 3)
		i3 = stacks->a->next->next->index;
	if (i1 > i2 && stacks->size == 2)
		return (sa(stacks));
	if (i1 < i2 && i1 < i3 && i2 > i3)
	{
		sa(stacks);
		return (ra(stacks));
	}
	if (i1 > i2 && i1 < i3 && i2 < i3)
		return (sa(stacks));
	if (i1 < i2 && i1 > i3 && i2 > i1)
	{
		ra(stacks);
		return (ra(stacks));
	}
	if (i1 > i2 && i1 > i3 && i2 < i3)
		return (ra(stacks));
	if (i1 > i2 && i1 > i3 && i2 > i3)
	{
		ra(stacks);
		return (sa(stacks));
	}
}

// 2 1 sa
// 1 3 2 sa ra
// 2 1 3 sa
//
// 2 3 1 ra ra
//
// 3 1 2 ra
// 3 2 1 ra sa
//
