#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define RED "\033[38;5;1m"
# define WHITE "\033[0m"
# define NUMBER_MALLOC 10
# define ERROR 2

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

typedef struct s_malloc
{
	void	*memory[NUMBER_MALLOC];
}	t_malloc;

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
}	t_stacks;

int		ft_strlen(char *s);
int		fatal(char *s);
t_list	*parse_arguments(char **av);
char	**ft_split(char const *s, char c);
int		check_arguments(char **av);
void	free_split(char **split);
int		convert_numbers(char **av);
#endif
