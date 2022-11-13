#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = NULL;
	node = (t_list *) malloc(sizeof (t_list));
	node->content = content;
	node->next = NULL;
	return (node);
}

int	ft_lstsize(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

t_list	*delete_fnode(t_list *list)
{
	t_list	*tmp;

	tmp = NULL;
	tmp = list;
	list = list->next;
	free(tmp);
	return (list);
}

t_list	*ft_last(t_list *lst)
{
	t_list	*list;

	list = NULL;
	list = lst;
	while (list->next)
		list = list->next;
	return (list);
}

void	ft_lstadd_front(t_list **lst, t_list *nnew)
{
	nnew->next = *lst;
	*lst = nnew;
}
