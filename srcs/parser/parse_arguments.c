#include "push_swap.h"

t_list *parse_arguments(char **av)
{

	if (check_arguments(av) == ERROR)
		return ((t_list *)ERROR);
	return ((t_list *)0x101010);
}
