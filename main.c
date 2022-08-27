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
	t_list *node;

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
	int		i;
	
	i = 1;
	head = malloc(sizeof(t_list*));
/*	tmp = head;
	while (av[i])
	{
		head->content = atoi(av[i]);
		head->next = malloc(sizeof(t_list*));
		head = head->next;
		i++;
	}
	head->next = NULL;
	head = tmp;*/
	//printls(head);
	while (av[i])
	{
		ft_lstadd_front(&head,ft_lstnew(atoi(av[i])));
		i++;
	}
	//sa(head);
	printls(head);
}

