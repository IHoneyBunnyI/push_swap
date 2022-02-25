#include "push_swap.h"
#include <unistd.h>

void	sa(t_stacks *stacks)
{
	int		tmp_i;
	int		tmp_data;;
	t_list	*tmp;

	tmp_i = stacks->a->i;
	tmp_data = stacks->a->data;
	tmp = stacks->a->n;
	stacks->a->data = tmp->data;
	stacks->a->i = tmp->i;
	tmp->data = tmp_data;
	tmp->i = tmp_i;
	write(1, "sa\n", 3);
}

void	sb(t_stacks *stacks)
{
	int		tmp_i;
	int		tmp_data;;
	t_list	*tmp;

	if (stacks->b == 0)
		return ;
	tmp_i = stacks->b->i;
	tmp_data = stacks->b->data;
	tmp = stacks->b->n;
	stacks->b->data = tmp->data;
	stacks->b->i = tmp->i;
	tmp->data = tmp_data;
	tmp->i = tmp_i;
	write(1, "sb\n", 3);
}

void	pb(t_stacks *stacks)
{
	t_list	*elem;

	if (stacks->a == 0)
		return ;
	elem = stacks->a;
	stacks->a = stacks->a->n;
	elem->n = 0;
	ft_lstadd_front(&stacks->b, elem);
	write(1, "pb\n", 3);
}

void	pa(t_stacks *stacks)
{
	t_list	*elem;

	if (stacks->b == 0)
		return ;
	elem = stacks->b;
	stacks->b = stacks->b->n;
	elem->n = 0;
	ft_lstadd_front(&stacks->a, elem);
	write(1, "pa\n", 3);
}

void	ra(t_stacks *stacks)
{
	t_list	*elem;

	elem = stacks->a;
	stacks->a = stacks->a->n;
	elem->n = 0;
	ft_lstadd_back(&stacks->a, elem);
	write(1, "ra\n", 3);
}

void	rb(t_stacks *stacks)
{
	t_list	*elem;

	if (stacks->b == 0)
		return;
	elem = stacks->b;
	stacks->b = stacks->b->n;
	elem->n = 0;
	ft_lstadd_back(&stacks->b, elem);
	write(1, "rb\n", 3);
}

void	rra(t_stacks *stacks)
{
	t_list	*last;
	t_list	*prev_last;
	
	last = stacks->a;
	prev_last = stacks->a;
	while (prev_last->n->n)
		prev_last = prev_last->n;
	while (last->n)
		last = last->n;
	prev_last->n = 0;
	last->n = stacks->a;
	stacks->a = last;
	write(1, "rra\n", 4);
}

void	rrb(t_stacks *stacks)
{
	t_list	*last;
	t_list	*prev_last;
	if (!stacks->b || !stacks->b->n)
		return;

	last = stacks->b;
	prev_last = stacks->b;
	while (prev_last->n->n)
		prev_last = prev_last->n;
	while (last->n)
		last = last->n;
	prev_last->n = 0;
	last->n = stacks->b;
	stacks->b = last;
	write(1, "rrb\n", 4);
}
