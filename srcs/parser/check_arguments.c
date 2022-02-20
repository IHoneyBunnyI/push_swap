#include "push_swap.h"

static int	only_digits_and_minus(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && str[i + 1] == 0)
		return (ERROR);
	if (str[i] == '-')
		i++;
	while (str[++i])
		if (str[i] > '9' || str[i] < '0')
			return (ERROR);
	return (0);
}

static int	convert_num(char *s)
{
	if (ft_atoi(s) == ERROR && s[0] == '2' && s[1] != '\0') // MAX INT
		return (ERROR);
	else if (ft_atoi(s) == ERROR && s[0] == '-' && s[2] != '\0') // MIN INT
		return (ERROR);
	return (0);
}

static int	check_str(char *str)
{
	if (only_digits_and_minus(str) == ERROR)
		return (ERROR);
	if (ft_strlen(str) > 11)
		return (ERROR);
	if (convert_num(str) == ERROR)
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
			if (check_str(av[i]) == ERROR)
				return (ERROR);
	}
	return (0);
}
