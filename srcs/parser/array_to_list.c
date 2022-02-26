/* ************************************************************************** */
/*         ⢀⣠⠤⠖⠚⠫⠭⡉⠉⠉⠙⠓⠲⠦⣤⡀*/
/*      ⣀⡴⠚⠉⣀⠤⠖⠒⠶⣤⣈⠑⢢⡀⠄⠄⠄⠄⠙⢿⣝⠻⣦⡀*/
/*    ⣠⠞⠁⠄⢀⡖⡡⣲⡶⠖⢦⡀⠈⠳⣄⠙⣄⠄⠄⠄⠄⠄⠻⣧⡈⠻⣆ */
/*  ⣠⠞⠁⠄⠄⠄⡎⡞⡟⢡⣄⣼⠇⡇⠄⠄⢸⠄⠈⢆⠄⠄⠄⠄⠄⢇⢷⠄⠸⣆*/
/*  ⡏⠄⠄⢰⠄⠄⡇⣇⣇⠠⠟⠛⣲⠃⠄⠄⣸⠄⠄⠈⣇⠄⠄⠄⠄⢸⠘⡇⠄⣹ */
/*  ⠙⠶⣄⡿⠄⠄⠳⡈⠛⠷⠶⠚⠁⠄⠄⣰⠃⠄⠄⠄⠘⢄⠄⠄⠄⠈⢧⣷⢰⠟*/
/*     ⡇⠄⠄⠄⠉⠲⠤⣤⣤⣤⠤⠞⠁⠄⠄⠄⠄⠄⢸⠄⠄⠄⠄⢨⣿⠋*/
/*     ⣷⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣠⡴⠖⡞⠛⢻⡉⠉⡟⡿*/
/*     ⢹⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣠⠖⠋⠄⠄⣚⣵⠆⣾⠙⣳⣿⠃*/
/*     ⠘⢷⡀⠄⠄⠄⠄⠄⠄⠄⣠⠟⠁⠄⠘⢿⣭⡥⢋⣼⠃⣠⣧⡏*/
/*      ⠈⢻⣄⡀⠄⠄⠄⠄⣼⡋⠛⠲⢦⣤⣤⣤⠶⢛⣡⠞⣱⠏*/
/*        ⠙⠓⢿⡦⢄⡠⠓⠯⣓⠒⠚⠁⠄⣠⣾⣯⠴⠞⠁*/
/*        ⣠⡾⠋⠄⠄⠉⠛⠳⠿⠿⢦⢖⡛⣯⡀⠸⣇*/
/*      ⢀⣼⠋⠄⠰⠖⠦⢤⣀⣀⠄⠄⠸⣼⠳⠟⡇⠄⢹⡄*/
/*      ⢸⡇⠄⠄⠄⠄⠄⠄⠄⠉⡗⠶⠶⠼⣦⣄⡇⠄⠄⣷*/
/*       ⢻⣄⠄⠄⠄⠄⠄⢀⡼⠃⠄⠄⠄⠄⠉⠙⡆⠄⣼*/
/*       ⢰⠟⠓⠶⣤⣤⣤⣞⡁⠄⠄⠄⠄⠄⠄⣰⠇⣰⠏*/
/*       ⣾⠄⠄⠄⣿⠤⢄⣉⠙⠓⠶⠶⠶⠶⠞⢻⠋⠁*/
/*       ⠸⣄⠄⢰⡇⠄⠄⠄⢉⡿⣯⠉⠉⠉⢉⣸  */
/*        ⠈⢛⡟⠙⠲⠦⢤⡟ ⢸⠛⠛⠛⠋⢹⡇*/
/*         ⢸⠇⠄⠄⠄⣾  ⢸⡆⠄⠄⠄⢠⡇*/
/*         ⢸⡶⠛⠳⣴⠃   ⣿⠄⠒⠈⠹⣧*/
/*         ⠈⠙⠛⠒⠋    ⠙⠓⠒⠒⠒⠛ */
/*   By: Leon*/
/*           */
/*   Created: Leon______________  by */
/*   Updated: Brawl_Stars _______ by */
/*                                   */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	get_index(int *num, int size, int data)
{
	int	i;

	i = -1;
	while (++i < size)
		if (num[i] == data)
			return (i);
	return (0);
}

t_list	*array_to_list(int *numbers, int size)
{
	int		i;
	int		*sorted;
	t_list	*res;
	t_list	*tmp;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return ((t_list *)ERROR);
	i = -1;
	while (++i < size)
		sorted[i] = numbers[i];
	sorted = sort_array(sorted, size);
	i = -1;
	res = 0;
	while (++i < size)
		ft_lstadd_back(&res, ft_lstnew(numbers[i]));
	i = -1;
	tmp = res;
	while (++i < size)
	{
		tmp->i = get_index(sorted, size, tmp->data);
		tmp = tmp->n;
	}
	free(sorted);
	return (res);
}
