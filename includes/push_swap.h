#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define RED "\033[38;5;1m"
# define WHITE "\033[0m"
# define NUMBER_MALLOC 10
# define ERROR 2

typedef struct s_list
{
	int	data;
	int	index;
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
	int		size;
}	t_stacks;

int		ft_strlen(char *s);
int		fatal(char *s);
t_list	*parse_arguments(char **av);
char	**ft_split(char const *s, char c);
int		check_arguments(char **av);
void	free_split(char **split);
int		ft_atoi(char *str);
int		find_space(char *str);
t_list	*array_to_list(int *numbers, int size);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int data);
int		*sort_array(int *array, int size);
int		size_list(t_list *l);

#endif
