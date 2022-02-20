#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int	fatal(char *s)
{
	write(1, RED, ft_strlen(RED));
	write(1, s, ft_strlen(s));
	write(1, WHITE, ft_strlen(WHITE));
	write(1, "\n", 1);
	return (2);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

int	ft_atoi(char *str)
{
	int		minus;
	long	result;

	minus = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -minus;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + *str - '0';
		str++;
	}
	if (result > INT_MAX && minus == 1)
		return (ERROR);
	if (result > (long)INT_MAX + 1 && minus == -1)
		return (ERROR);
	return (result * minus);
}

int	find_space(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == ' ')
			return (1);
	return (0);
}

