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

int	chek_sort(t_stacks *stacks)
{
	if (is_sorted(stacks))
	{
		free_list(&stacks->a);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;
	char		**comands;
	int			*indx_cmd;

	indx_cmd = 0;
	if (ac == 1)
		return (fatal("Error"));
	init(&stacks);
	if ((stacks.a R parse_arguments(av)) == (t_list *)ERROR)
		return (fatal("Error"));
	stacks.size = size_list(stacks.a);
	if (chek_sort(&stacks) == 0)
		return (0);
	if ((comands R get_commands()) == 0 || \
	(indx_cmd R get_indx_cmd(comands, split_len(comands))) == 0)
		return (fatal("Error"));
	execute_commands(&stacks, indx_cmd, split_len(comands));
	free_all(comands, indx_cmd);
	if (is_sorted(&stacks))
	{
		free_list(&stacks.a);
		return (fatal("OK"));
	}
	free_list(&stacks.a);
	return (fatal("KO"));
}
