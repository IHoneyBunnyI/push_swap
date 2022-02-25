#include "push_swap.h"

int	min_index(t_list *list)
{
	int	min;
	t_list *a;

	min = list->i;
	a = list->n;
	while (a)
	{
		if (a->i < min)
			min = a->i;
		a = a->n;
	}
	return (min);
}

int	steps_to_next(t_list *list)
{
	int	i;
	t_list *a;

	a = list;
	i = 0;
	while (a)
	{
		if (a->i == min_index(list))
			return (i);
		i++;
		a = a->n;
	}
	return (i);
}

void	sort5(t_stacks *stacks)
{
	while (size_list(stacks->a) != 3)
	{
		if (stacks->a->i == min_index(stacks->a))
			pb(stacks);
		if (steps_to_next(stacks->a) > stacks->size / 2)
			rra(stacks);
		else
			ra(stacks);
	}
	sort3(stacks);
	while (size_list(stacks->b) != 0)
	{
		if (stacks->size == 5 && stacks->b->i == 0)
			sb(stacks);
		pa(stacks);
		pa(stacks);
	}
}
