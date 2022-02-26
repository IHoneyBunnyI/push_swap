#ifndef CHECKER_H
# define CHECKER_H
# define ERROR 2

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

int		size_list(t_list *l);
int		fatal(char *s);
t_list	*parse_arguments(char **av);
#endif
