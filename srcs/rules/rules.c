#include "push_swap.h"
#include <unistd.h>

void	sa(t_list *a)
{
	int	tmp_index;
	int	tmp_data;;
	t_list *tmp;

	tmp_index = a->index;
	tmp_data = a->data;
	tmp = a->next;
	a->data = tmp->data;
	a->index = tmp->index;
	tmp->data = tmp_data;
	tmp->index = tmp_index;
	write(1, "sa\n", 3);
}

void	sb(t_list *b)
{
	int	tmp_index;
	int	tmp_data;;
	t_list *tmp;

	tmp_index = b->index;
	tmp_data = b->data;
	tmp = b->next;
	b->data = tmp->data;
	b->index = tmp->index;
	tmp->data = tmp_data;
	tmp->index = tmp_index;
	write(1, "sb\n", 3);
}

void	pb(t_stacks *stacks) // не то
{
	stacks->b = stacks->a;
	stacks->a = stacks->a->next;
	stacks->b->next = 0;
	write(1, "pb\n", 3);
}
