/* ************************************************************************** */
/*       ⢀⣠⠤⠖⠚⠫⠭⡉⠉⠉⠙⠓⠲⠦⣤⡀*/
/*    ⣀⡴⠚⠉⣀⠤⠖⠒⠶⣤⣈⠑⢢⡀⠄⠄⠄⠄⠙⢿⣝⠻⣦⡀*/
/*  ⣠⠞⠁⠄⢀⡖⡡⣲⡶⠖⢦⡀⠈⠳⣄⠙⣄⠄⠄⠄⠄⠄⠻⣧⡈⠻⣆ */
/*⣠⠞⠁⠄⠄⠄⡎⡞⡟⢡⣄⣼⠇⡇⠄⠄⢸⠄⠈⢆⠄⠄⠄⠄⠄⢇⢷⠄⠸⣆*/
/*⡏⠄⠄⢰⠄⠄⡇⣇⣇⠠⠟⠛⣲⠃⠄⠄⣸⠄⠄⠈⣇⠄⠄⠄⠄⢸⠘⡇⠄⣹ */
/*⠙⠶⣄⡿⠄⠄⠳⡈⠛⠷⠶⠚⠁⠄⠄⣰⠃⠄⠄⠄⠘⢄⠄⠄⠄⠈⢧⣷⢰⠟*/
/*   ⡇⠄⠄⠄⠉⠲⠤⣤⣤⣤⠤⠞⠁⠄⠄⠄⠄⠄⢸⠄⠄⠄⠄⢨⣿⠋*/
/*   ⣷⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣠⡴⠖⡞⠛⢻⡉⠉⡟⡿*/
/*   ⢹⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣠⠖⠋⠄⠄⣚⣵⠆⣾⠙⣳⣿⠃*/
/*   ⠘⢷⡀⠄⠄⠄⠄⠄⠄⠄⣠⠟⠁⠄⠘⢿⣭⡥⢋⣼⠃⣠⣧⡏*/
/*    ⠈⢻⣄⡀⠄⠄⠄⠄⣼⡋⠛⠲⢦⣤⣤⣤⠶⢛⣡⠞⣱⠏*/
/*      ⠙⠓⢿⡦⢄⡠⠓⠯⣓⠒⠚⠁⠄⣠⣾⣯⠴⠞⠁*/
/*      ⣠⡾⠋⠄⠄⠉⠛⠳⠿⠿⢦⢖⡛⣯⡀⠸⣇*/
/*    ⢀⣼⠋⠄⠰⠖⠦⢤⣀⣀⠄⠄⠸⣼⠳⠟⡇⠄⢹⡄*/
/*    ⢸⡇⠄⠄⠄⠄⠄⠄⠄⠉⡗⠶⠶⠼⣦⣄⡇⠄⠄⣷*/
/*     ⢻⣄⠄⠄⠄⠄⠄⢀⡼⠃⠄⠄⠄⠄⠉⠙⡆⠄⣼*/
/*     ⢰⠟⠓⠶⣤⣤⣤⣞⡁⠄⠄⠄⠄⠄⠄⣰⠇⣰⠏*/
/*     ⣾⠄⠄⠄⣿⠤⢄⣉⠙⠓⠶⠶⠶⠶⠞⢻⠋⠁*/
/*     ⠸⣄⠄⢰⡇⠄⠄⠄⢉⡿⣯⠉⠉⠉⢉⣸  */
/*      ⠈⢛⡟⠙⠲⠦⢤⡟ ⢸⠛⠛⠛⠋⢹⡇*/
/*       ⢸⠇⠄⠄⠄⣾  ⢸⡆⠄⠄⠄⢠⡇*/
/*       ⢸⡶⠛⠳⣴⠃   ⣿⠄⠒⠈⠹⣧*/
/*       ⠈⠙⠛⠒⠋    ⠙⠓⠒⠒⠒⠛ */
/*   By: Leon*/
/*           */
/*   Created: Leon______________  by */
/*   Updated: Brawl_Stars _______ by */
/*                                   */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>
#include <stdlib.h>

int	is_sorted(t_stacks *stacks)
{
	t_list	*a;

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

void	init(t_stacks *stacks)
{
	stacks->a = 0;
	stacks->b = 0;
}

char	**get_commands(void)
{
	char	*tmp;
	char	*line;
	char	**res;

	line = 0;
	res = 0;
	tmp = 0;
	while (get_next_line(0, &tmp))
	{
		line = ft_strjoin(line, tmp);
		line = ft_strjoin(line, " ");
		free(tmp);
	}
	res = ft_split(line, ' ');
	if (!res)
		return (0);
	return (res);
}

void	fill_res(int *res, int i, char *comand)
{
	if (ft_strcmp(comand, "sa") == 0)
		res[i] = 1;
	if (ft_strcmp(comand, "sb") == 0)
		res[i] = 2;
	if (ft_strcmp(comand, "ss") == 0)
		res[i] = 3;
	if (ft_strcmp(comand, "pa") == 0)
		res[i] = 4;
	if (ft_strcmp(comand, "pb") == 0)
		res[i] = 5;
	if (ft_strcmp(comand, "ra") == 0)
		res[i] = 6;
	if (ft_strcmp(comand, "rb") == 0)
		res[i] = 7;
	if (ft_strcmp(comand, "rr") == 0)
		res[i] = 8;
	if (ft_strcmp(comand, "rra") == 0)
		res[i] = 9;
	if (ft_strcmp(comand, "rrb") == 0)
		res[i] = 10;
	if (ft_strcmp(comand, "rrr") == 0)
		res[i] = 11;
	else 
	{
		fatal("Error Comand!");
	}

}

int	*get_indx_cmd(char **comands, int size)
{
	int	i;
	int	*res;

	res = malloc(sizeof(int) * size);
	if (!res)
		return (0);
	i = -1;
	while (comands[++i])
		fill_res(res, i, comands[i]);
	return (res);
}


int	main(int ac, char **av)
{
	t_stacks	stacks;
	char		**comands;
	int			*indx_cmd;

	indx_cmd = 0;
	if (ac == 1)
		return (fatal("Give me numbers, I will check it"));
	init(&stacks);
	stacks.a = parse_arguments(av);
	if (stacks.a == (t_list *)ERROR)
		return (fatal("Error arguments"));
	stacks.size = size_list(stacks.a);
	if (is_sorted(&stacks))
		return (fatal("Stack is sorted!"));
	comands = get_commands();
	if (comands == 0)
		return (fatal("Error comands!"));
	indx_cmd = get_indx_cmd(comands, split_len(comands));
	if (indx_cmd == 0)
		return (fatal("malloc Error!"));
}
