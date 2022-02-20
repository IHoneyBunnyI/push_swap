#include "push_swap.h"
static int	find_space(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == ' ')
			return (1);
	return (0);
}

static int	only_digits_and_minus(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[++i])
		if (str[i] > '9' || str[i] < '0')
			return (ERROR);
	return (0);
}

static int	check_str(char *str)
{
	if (only_digits_and_minus(str) == ERROR)
		return (ERROR);
	if (ft_strlen(str) > 11)
		return (ERROR);
	return (0);
}

int	check_arguments(char **av)
{
	int		i;
	char	**split;
	int		j;

	i = 0;
	while (av[++i])
	{
		if (find_space(av[i]))
		{
			split = ft_split(av[i], ' ');
			j = -1;
			while (split[++j])
				if (check_str(split[j]) == ERROR)
					return (ERROR);
			free_split(split);
		}
		else
		{
			if (check_str(av[i]) == ERROR)
				return (ERROR);
		}
	}
	return (0);
}
