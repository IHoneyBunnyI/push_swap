#include "push_swap.h"
#include <stdio.h>

void	print_list(t_list *list)
{
	t_list *tmp;

	tmp = list;
	while (tmp)
	{
		printf("data: %d \tindex: %d\n", tmp->data, tmp->index);
		tmp = tmp->next;
	}
	/*printf("\n");*/
}

void	print_lists(t_stacks *stacks)
{
	t_list *tmpa;
	t_list *tmpb;

	tmpa = stacks->a;
	tmpb = stacks->b;
	while (tmpa || tmpb)
	{
		printf("%sd: %d \ti: %d \t%sd: %d \t i: %d %s \n",	BLUE, tmpa ? tmpa->data : 0, tmpa ? tmpa->index : 0, \
															ORANGE, tmpb ? tmpb->data : 0, tmpb ? tmpb->index : 0, \
															WHITE);
		if (tmpa)
			tmpa = tmpa->next;
		if (tmpb)
			tmpb = tmpb->next;
	}
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
	/*print_list("a", stacks.a);*/
	/*print_list(stacks.b);*/
	print_lists(&stacks);
	sa(stacks.a);
	print_lists(&stacks);
	/*print_list("a", stacks.a);*/
	/*print_list("b", stacks.b);*/
	/*if (stacks.size <= 3)*/
		/*sort3(stacks);*/
	/*if (stacks.size <= 5)*/
		/*sort5(stacks);*/
	/*if (stacks.size <= 100)*/
		/*sort100(stacks);*/
	/*if (stacks.size <= 500)*/
		/*sort500(stacks);*/
	return 0;
}
