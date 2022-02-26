#include "checker.h"
#include <stdlib.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	split_len(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

void	free_list(t_list **lst)
{
	t_list *plist;
	t_list *ptmp;

	if (!*lst)
		return ;
	plist = *lst;
	ptmp = *lst;
	while (plist)
	{
		ptmp = plist->n;
		free(plist);
		plist = ptmp;
	}
	*lst = NULL;
}

void	free_all(char **comands, int *indx_cmd)
{
	free(indx_cmd);
	free_split(comands);
}
