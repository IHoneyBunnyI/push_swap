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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define RED "\033[38;5;1m"
# define WHITE "\033[0m"
# define BLUE "\e[38;5;87m"
# define ORANGE "\e[38;5;208m"
# define NUMBER_MALLOC 10
# define ERROR 2
# define R =

typedef struct s_list
{
	int				data;
	int				i;
	struct s_list	*n;
}	t_list;

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
	int		size;
}	t_stacks;

int		ft_strlen(char *s);
int		fatal(char *s);
t_list	*parse_arguments(char **av);
char	**ft_split(char const *s, char c);
int		check_arguments(char **av);
void	free_split(char **split);
void	free_list(t_list **lst);
int		ft_atoi(char *str);
int		find_space(char *str);
t_list	*array_to_list(int *numbers, int size);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int data);
int		*sort_array(int *array, int size);
void	print_lists(t_stacks *stacks);
int		size_list(t_list *l);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	sa(t_stacks *stacks, int w);
void	sb(t_stacks *stacks, int w);
void	ss(t_stacks *stacks, int w);
void	pa(t_stacks *stacks, int w);
void	pb(t_stacks *stacks, int w);
void	ra(t_stacks *stacks, int w);
void	rb(t_stacks *stacks, int w);
void	rr(t_stacks *stacks, int w);
void	rra(t_stacks *stacks, int w);
void	rrb(t_stacks *stacks, int w);
void	rrr(t_stacks *stacks, int w);
void	sort_more(t_stacks *stacks, int interval);
void	sort3(t_stacks *stacks);
void	sort5(t_stacks *stacks);
void	sort100(t_stacks *stacks);
void	sort500(t_stacks *stacks);

#endif
