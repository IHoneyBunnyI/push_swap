#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

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
