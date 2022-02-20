#include "push_swap.h"
#include <stdlib.h>

static int num_array(char **av)
{
	int		i;
	char	**split;
	int		j;
	int		num;

	i = 0;
	num = 0;
	while (av[++i])
	{
		if (find_space(av[i]))
		{
			split = ft_split(av[i], ' ');
			j = -1;
			while (split[++j])
				num++;
			free_split(split);
		}
		else
			num++;
	}
	return (num);
}

static int	*convert_numbers_to_array(char **av, int size)
{
	int	num;
	int i;
	int j;
	int *res;
	char **split;

	res = malloc(sizeof(int) * size);
	if (!res)
		return ((int *)ERROR);
	i = 0;
	num = 0;
	while (av[++i])
	{
		if (find_space(av[i]))
		{
			split = ft_split(av[i], ' ');
			j = -1;
			while (split[++j])
				res[num++] = ft_atoi(split[j]);
			free_split(split);
		}
		else
			res[num++] = ft_atoi(av[i]);
	}
	return (res);
}

/*static int	find_duplicates(int *nums)*/
/*{*/
	/*(void)nums;*/
	/*return (0);*/
/*}*/

#include <stdio.h>
t_list *parse_arguments(char **av)
{
	/*t_list	*list;*/
	int		*numbers;
	int		size;

	if (check_arguments(av) == ERROR)
		return ((t_list *)ERROR);
	size = num_array(av);
	numbers = convert_numbers_to_array(av, size);
	for (int i = 0; i < size; i++)
		printf("\033[33m%d \033[0m", numbers[i]);
	/*if (find_duplicates(numbers) == ERROR)*/
		/*return ((t_list *)ERROR);*/
	return ((t_list *)0x101010);
}
