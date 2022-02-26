#include "push_swap.h"

int	max_index(t_list *list)
{
	int		max;
	t_list	*a;

	max = list->i;
	a = list->n;
	while (a)
	{
		if (a->i > max)
			max = a->i;
		a = a->n;
	}
	return (max);
}

int	steps_to_next_max(t_list *list)
{
	int		i;
	t_list	*a;

	a = list;
	i = 0;
	while (a)
	{
		if (a->i == max_index(list))
			return (i);
		i++;
		a = a->n;
	}
	return (i);
}

void	sort_a_from_b(t_stacks *stacks)
{
	while (size_list(stacks->b) != 0)
	{
		if (stacks->b->i == max_index(stacks->b))
			pa(stacks);
		if (steps_to_next_max(stacks->b) > (size_list(stacks->b) / 2))
			rrb(stacks);
		else
			rb(stacks);
	}
}

void	sort_more(t_stacks *stacks, int interval)
{
	int	interval_start;

	interval_start = 0;
	while (size_list(stacks->a) != 0)
	{
		if (stacks->a->i <= interval_start && interval_start > 1)
		{
			pb(stacks);
			rb(stacks);
			interval_start++;
		}
		else if (stacks->a->i <= interval_start + interval)
		{
			pb(stacks);
			interval_start++;
		}
		else if (stacks->a->i > interval_start)
			ra(stacks);
	}
	sort_a_from_b(stacks);
}

void	sort100(t_stacks *stacks)
{
	int	interval;

	interval = 15;
	sort_more(stacks, interval);
}
