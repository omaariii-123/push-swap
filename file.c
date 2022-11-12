#include"push_swap.h"
void    ft_lstadd_back(t_list **lst, t_list *nnew)
{
	if(!*lst)
	{
		*lst = nnew;
		return ;
	}
 
  	ft_last(*lst)->next = nnew;
}

void    printls(t_list *node)
{

	while (node)
        {
                printf("%d\n",node->content);
                node = node->next;
        }
}

