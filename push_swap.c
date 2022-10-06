/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:54:30 by yomari            #+#    #+#             */
/*   Updated: 2022/08/22 10:55:14 by yomari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdlib.h>
#include <stdio.h>

t_list  *ft_lstnew(int content)
{
        t_list *node = NULL;

        node=(t_list *) malloc(sizeof(t_list));
        node->content = content;
	node->next = NULL;
        return (node);
}

t_list	*delete_fnode(t_list *list)
{
	t_list *tmp = NULL;

	tmp = list;
	list = list->next;
	free(tmp);
	return (list);
}

t_list  *ft_last(t_list *lst)
{
        t_list *list = NULL;

        list = lst;
        while (list->next)
                list = list->next;
        return list;

}

void    ft_lstadd_front(t_list **lst, t_list *new)
{
        new->next = *lst;
        *lst = new;
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
	if(!*lst)
	{
		*lst = new;
		return ;
	}
        ft_last(*lst)->next = new;
}

void    printls(t_list *node)
{

	while (node)
        {
                printf("%d\n",node->content);
                node = node->next;
        }
}

void	s(t_list **lst)
{
	t_list *new = NULL;
	int	tmp;

	tmp = (*lst)->content;
	*lst = delete_fnode(*lst);
	new = ft_lstnew(tmp);
	new->next = (*lst)->next;
	(*lst)->next = new;
}

void	p(t_list **stack_b, t_list **stack_a)
{
	int	i;

	i = (*stack_a)->content;
	*stack_a = delete_fnode(*stack_a);
	ft_lstadd_front (stack_b, ft_lstnew(i));
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	p(stack_a, stack_b);
}
void	pb(t_list **stack_a, t_list **stack_b)
{
	p(stack_b, stack_a);
}

void	ra(t_list **lst)
{
	int	tmp;
	tmp = (*lst)->content;
	*lst = delete_fnode(*lst);
	ft_lstadd_back(lst, ft_lstnew(tmp));

}
void	rr(t_list **lst)
{
	t_list *tmp = NULL;
	int	i;

	tmp = *lst;
	while(tmp->next->next)
		tmp = tmp->next;
	i = tmp->next->content;
	free(tmp->next);
	tmp->next = NULL;
	ft_lstadd_front(lst, ft_lstnew(i));
	
}

void	three_nums(int *nb, t_list **lst)
{
	int	a;
	int	b;
	int	c;

	a = nb[0];
	b = nb[1];
	c = nb[2];
	//printf("a is : %d, b is : %d, c is : %d\n", a, b, c);
	if (a < b && b < c && a < c)
		return;
	else if ( a < b && b > c && a < c)
	{
		s(lst);
		ra(lst);
		write(1, "sa\nra\n", 6);
		return;
	}
	else if (a < b && b > c && a > c)
	{
		rr(lst);
		write(1, "rra\n", 4);
		return;
	}
	else if (a > b && b > c && a > c)
	{
		s(lst);
		rr(lst);
		write(1, "sa\nrra\n", 7);
		return;
	}
	else if (a > b && b < c && a > c)
	{
		ra(lst);
		write(1, "ra\n", 3);
	}
	else if (a > b && b < c && a < c)
	{
		s(lst);
		write(1, "sa\n", 3);
		return;
	}
}

void	check_double(t_list *lst, int *nums, int nb)
{
	int	i;
	int	n;
	int	c;

	while(lst)
	{
		n = nb;
		c = 0;
		i = 0;
		while(n)
		{
			if (lst->content == nums[i])
				c++;
			n--;
			i++;
		}
		if (c > 1)
			exit(0);
		lst = lst->next;
	}

}

int     main(int ac, char **av)
{
	t_list	*stack_b = NULL;
       	t_list *head = NULL;
      	int *nb = NULL; 
	int             i;
	int	j;

	stack_b = malloc(sizeof(t_list));
	stack_b->content = 7;
        i = 1;
	j = 0;
	nb = malloc(sizeof(int) * (ac - 1));
        
	while (av[i])
        {
                nb[j] = atoi(av[i]);
		ft_lstadd_back(&head, ft_lstnew(nb[j]));
                i++;
		j++;
        }
	check_double(head,nb , (ac - 1));
        //ptr = ft_last(&head);
       // ft_lstadd_back(&head, ft_lstnew(9));
//       pa(&head, &stack_b);
	//s(&head);
	//ra(&head);
	if (ac == 4)
		three_nums(nb, &head);
		
        printls(head);
	nb = NULL;
	free(nb);
}
