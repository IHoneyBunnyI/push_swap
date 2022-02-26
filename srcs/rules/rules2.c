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

void	sb(t_stacks *stacks, int w)
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
	if (w)
		write(1, "sb\n", 3);
}

void	pb(t_stacks *stacks, int w)
{
	t_list	*elem;

	if (stacks->a == 0)
		return ;
	elem = stacks->a;
	stacks->a = stacks->a->n;
	elem->n = 0;
	ft_lstadd_front(&stacks->b, elem);
	if (w)
		write(1, "pb\n", 3);
}

void	rb(t_stacks *stacks, int w)
{
	t_list	*elem;

	if (stacks->b == 0)
		return ;
	elem = stacks->b;
	stacks->b = stacks->b->n;
	elem->n = 0;
	ft_lstadd_back(&stacks->b, elem);
	if (w)
		write(1, "rb\n", 3);
}

void	rrb(t_stacks *stacks, int w)
{
	t_list	*last;
	t_list	*prev_last;

	if (!stacks->b || !stacks->b->n)
		return ;
	last = stacks->b;
	prev_last = stacks->b;
	while (prev_last->n->n)
		prev_last = prev_last->n;
	while (last->n)
		last = last->n;
	prev_last->n = 0;
	last->n = stacks->b;
	stacks->b = last;
	if (w)
		write(1, "rrb\n", 4);
}
