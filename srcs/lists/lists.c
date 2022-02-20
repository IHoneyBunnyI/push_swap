#include "push_swap.h"
#include <stdlib.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *plst;

	if (!lst)
		return ;
	plst = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (!new)
		return ;
	while (plst->next)
		plst = plst->next;
	plst->next = new;
}

t_list	*ft_lstnew(void *data)
{
	t_list *new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}
