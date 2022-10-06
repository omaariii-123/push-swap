/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:12:31 by yomari            #+#    #+#             */
/*   Updated: 2022/08/25 17:52:02 by yomari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_list	*ft_last(t_list **lst)
{
	t_list *list = NULL;

	list = *lst;
	while (list->next)
		list = list->next;
	return list;

}
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *tmp;
	
	tmp = *lst;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}

void	sa(t_list *node)
{
	int	i;

	i = node->content;
	node->content = node->next->content;
	node->next->content = i;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstnew(int content)
{
	t_list *node = NULL;

	node= malloc(sizeof(t_list*));
	node->content = content;
	return (node);
}

void	printls(t_list *node)
{
	while (node->next != NULL)
	{
		printf("%d\n", node->content);
		node = node->next;
	}
}
int	main(int ac, char **av)
{
	t_list *head = NULL;
	t_list *tmp = NULL;
	t_list *ptr = NULL;
	int		i;
	
	i = 1;
	head = malloc(sizeof(t_list*));
	tmp = head;
	while (av[i])
	{
		tmp->content = atoi(av[i]);
		tmp->next = malloc(sizeof(t_list);
		tmp = tmp->next;
		i++;
	}
	tmp = NULL;
	//ptr = ft_last(&head);
	//printf("%s\n"), tmp->next;
	//ft_lstadd_back(&head, ft_lstnew(9));
	//sa(head);
	printls(head);
}

