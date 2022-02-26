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

#include "push_swap.h"
#include <unistd.h>

void	sa(t_stacks *stacks)
{
	int		tmp_i;
	int		tmp_data;
	t_list	*tmp;

	tmp_i = stacks->a->i;
	tmp_data = stacks->a->data;
	tmp = stacks->a->n;
	stacks->a->data = tmp->data;
	stacks->a->i = tmp->i;
	tmp->data = tmp_data;
	tmp->i = tmp_i;
	write(1, "sa\n", 3);
}

void	sb(t_stacks *stacks)
{
	int		tmp_i;
	int		tmp_data;
	t_list	*tmp;

	if (stacks->b == 0)
		return ;
	tmp_i = stacks->b->i;
	tmp_data = stacks->b->data;
	tmp = stacks->b->n;
	stacks->b->data = tmp->data;
	stacks->b->i = tmp->i;
	tmp->data = tmp_data;
	tmp->i = tmp_i;
	write(1, "sb\n", 3);
}

void	pb(t_stacks *stacks)
{
	t_list	*elem;

	if (stacks->a == 0)
		return ;
	elem = stacks->a;
	stacks->a = stacks->a->n;
	elem->n = 0;
	ft_lstadd_front(&stacks->b, elem);
	write(1, "pb\n", 3);
}
