/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:17:58 by yomari            #+#    #+#             */
/*   Updated: 2022/11/14 21:18:01 by yomari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	two_nums(t_list **lst)
{
	int	a;
	int	b;

	a = (*lst)->content;
	b = (*lst)->next->content;
	if (a > b)
		s(lst, "sa\n");
	else
		return ;
}

void	three_nums(t_list **lst)
{
	int	a;
	int	b;
	int	c;

	a = (*lst)->content;
	b = (*lst)->next->content;
	c = (*lst)->next->next->content;
	if (a < b && b < c && a < c)
		return ;
	else if (a < b && b > c && a < c)
	{
		s(lst, "sa\n");
		ra(lst);
	}
	else if (a < b && b > c && a > c)
		rr(lst);
	else if (a > b && b > c && a > c)
	{
		s(lst, "sa\n");
		rr(lst);
	}
	else if (a > b && b < c && a > c)
		ra(lst);
	else if (a > b && b < c && a < c)
		s(lst, "sa\n");
}

void	four_nums(t_list **st_a, t_list **st_b, t_info inf)
{
	while ((*st_a)->content != 0)
	{
		if (inf.zero > 2)
			rr(st_a);
		else
			ra(st_a);
	}
	pb(st_a, st_b);
	three_nums(st_a);
	pa(st_a, st_b);
}

void	five_nums(t_list **st_a, t_list **st_b, t_info inf)
{
	while ((*st_a)->content != 1)
	{
		if (inf.one > 2)
			rr(st_a);
		else
			ra(st_a);
	}
	pb(st_a, st_b);
	four_nums(st_a, st_b, inf);
	pa(st_a, st_b);
	s(st_a, "sa\n");
}

void	ft_lstadd_back(t_list **lst, t_list *nnew)
{
	if (!*lst)
	{
		*lst = nnew;
		return ;
	}
	ft_last(*lst)->next = nnew;
}
