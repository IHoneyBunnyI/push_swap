#include "push_swap.h"
#include <stdio.h>

void	print_list(t_list *list)
{
	t_list *tmp;

	tmp = list;
	while (tmp)
	{
		printf("data: %d \ti: %d\n", tmp->data, tmp->i);
		tmp = tmp->n;
	}
	/*printf("\n");*/
}

void	print_lists(t_stacks *stacks)
{
	t_list *tmpa;
	t_list *tmpb;
	int i;

	tmpa = stacks->a;
	tmpb = stacks->b;
	while (tmpa || tmpb)
	{
		if (tmpa)
		{
			i = dprintf(2, "%sd: %d \ti: %d \t%s", BLUE, tmpa->data, tmpa->i, WHITE);
			tmpa = tmpa->n;
		}
		if (tmpb)
		{
			if (i == 0)
				dprintf(2, "\t\t%sd: %d \t i: %d %s", ORANGE ,tmpb->data,tmpb->i, WHITE);
			else
				dprintf(2, "%sd: %d \t i: %d %s", ORANGE ,tmpb->data,tmpb->i, WHITE);
			tmpb = tmpb->n;
			i = 0;
		}
		dprintf(2, "\n");
	}
}

int	is_sorted(t_stacks *stacks)
{
	t_list *a;

	a = stacks->a;
	if (size_list(stacks->a) != stacks->size)
		return (0);
	while (a->n)
	{
		if (a->i < a->n->i)
			a = a->n;
		else
			return (0);
	}
	return (1);
}

void	init(t_stacks *stacks, t_malloc *malloc)
{
	int	i;

	i = -1;
	stacks->a = 0;
	stacks->b = 0;
	while (++i < NUMBER_MALLOC)
		malloc->memory[i] = 0;
	malloc->memory[0] = stacks->a;
	malloc->memory[1] = stacks->b;
}

int main(int ac, char **av)
{
	t_stacks	stacks;
	t_malloc	malloc;
	
	if (ac == 1)
		return (fatal("Give me numbers, I will sort!"));
	init(&stacks, &malloc);
	stacks.a = parse_arguments(av);
	if (stacks.a == (t_list *)ERROR)
		return (fatal("Error arguments"));
	stacks.size = size_list(stacks.a);
	if (is_sorted(&stacks))
		return (fatal("Stack is sorted!"));
	if (stacks.size <= 3)
		sort3(&stacks);
	if (stacks.size > 3 && stacks.size <= 5)
		sort5(&stacks);
	if (stacks.size > 5 && stacks.size <= 100)
		sort100(&stacks);
	if (stacks.size > 100)
		sort500(&stacks);
	return 0;
}
