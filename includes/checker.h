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

#ifndef CHECKER_H
# define CHECKER_H
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

typedef void	(*t_rule)(t_stacks *stacks, int w);

int		size_list(t_list *l);
int		fatal(char *s);
t_list	*parse_arguments(char **av);
int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char *s2);
int		norminette(char *s);
char	**ft_split(char const *s, char c);
int		check_str(char *str);
int		ft_strcmp(char *s1, char *s2);
int		split_len(char **split);
void	execute_commands(t_stacks *stacks, int *indx_cmd, int len);
char	**get_commands(void);
int		*get_indx_cmd(char **comands, int size);
void	free_split(char **split);
void	free_all(char **comands, int *indx_cmd);
void	free_list(t_list **lst);
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

#endif
