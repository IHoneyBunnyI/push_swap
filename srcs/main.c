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
	return 0;
}
