#include "push_swap.h"
#include <unistd.h>

void	sa(t_stacks *stacks)
{
	int		tmp_index;
	int		tmp_data;;
	t_list	*tmp;

	tmp_index = stacks->a->index;
	tmp_data = stacks->a->data;
	tmp = stacks->a->next;
	stacks->a->data = tmp->data;
	stacks->a->index = tmp->index;
	tmp->data = tmp_data;
	tmp->index = tmp_index;
	write(1, "sa\n", 3);
}

void	sb(t_stacks *stacks)
{
	int		tmp_index;
	int		tmp_data;;
	t_list	*tmp;

	tmp_index = stacks->b->index;
	tmp_data = stacks->b->data;
	tmp = stacks->b->next;
	stacks->b->data = tmp->data;
	stacks->b->index = tmp->index;
	tmp->data = tmp_data;
	tmp->index = tmp_index;
	write(1, "sb\n", 3);
}

void	pb(t_stacks *stacks)
{
	t_list	*elem;

	elem = stacks->a;
	stacks->a = stacks->a->next;
	elem->next = 0;
	ft_lstadd_front(&stacks->b, elem);
	write(1, "pb\n", 3);
}

void	pa(t_stacks *stacks)
{
	t_list	*elem;

	elem = stacks->b;
	stacks->b = stacks->b->next;
	elem->next = 0;
	ft_lstadd_front(&stacks->a, elem);
	write(1, "pa\n", 3);
}

void	ra(t_stacks *stacks)
{
	t_list	*elem;

	elem = stacks->a;
	stacks->a = stacks->a->next;
	elem->next = 0;
	ft_lstadd_back(&stacks->a, elem);
	write(1, "ra\n", 3);
}

void	rb(t_stacks *stacks)
{
	t_list	*elem;

	elem = stacks->b;
	stacks->b = stacks->b->next;
	elem->next = 0;
	ft_lstadd_back(&stacks->b, elem);
	write(1, "rb\n", 3);
}

#include <stdio.h>
void	rra(t_stacks *stacks)
{
	t_list	*last;
	t_list	*prev_last;
	
	last = stacks->a;
	prev_last = stacks->a;
	while (prev_last->next->next)
		prev_last = prev_last->next;
	while (last->next)
		last = last->next;
	prev_last->next = 0;
	last->next = stacks->a;
	stacks->a = last;
	write(1, "rra\n", 4);
}

void	rrb(t_stacks *stacks)
{
	t_list	*last;
	t_list	*prev_last;

	last = stacks->b;
	prev_last = stacks->b;
	while (prev_last->next->next)
		prev_last = prev_last->next;
	while (last->next)
		last = last->next;
	prev_last->next = 0;
	last->next = stacks->b;
	stacks->b = last;
	write(1, "rrb\n", 4);
}
