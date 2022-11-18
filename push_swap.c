/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:54:30 by yomari            #+#    #+#             */
/*   Updated: 2022/11/14 22:44:17 by yomari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdlib.h>
#include <stdio.h>

void	check_sorted(int *nums, int size)
{
	int	i;

	i = 0;
	while (size)
	{
		if (nums[i] < nums[i + 1])
		{
			size--;
			i++;
		}
		else
			break;
	}
	if(size == 0)
		exit(0);
}

void	func(int ac, char **av, t_list **head, t_info *inf)
{
	int	i;
	int	j;
	int	*nb;

	i = 1;
	j = 0;
	nb = malloc(sizeof(int) * (ac - 1));
	while (av[i])
	{
		nb[j] = ft_atoi(av[i]);
		ft_lstadd_back(head, ft_lstnew(nb[j]));
		i++;
		j++;
	}
	check_double(*head, nb, (ac - 1));
	check_sorted(nb ,j - 1);
	b_sort(j, nb);
	convert_nums(head, nb, j, inf);
	free(nb);
}

void	radix_sort(t_list **stack_a, t_list **stack_b, int sz)
{
	int	bits;
	int	tmp;
	int	i;
	int	nb;

	i = 0;
	bits = how_many_bits(sz);
	while (i < bits)
	{
		tmp = sz;
		while (tmp--)
		{
			nb = (*stack_a)->content;
			if (((nb >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (*stack_b != NULL)
			pa(stack_a, stack_b);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_b;
	t_list	*head;
	t_info	inf;
	int		negation;
	int		i;

	i = 1;
	negation = 1;
	check_error(av, negation, i);
	head = NULL;
	stack_b = NULL;
	func(ac, av, &head, &inf);
	if (ac == 3)
		two_nums(&head);
	if (ac == 4)
		three_nums(&head);
	if (ac == 5)
		four_nums(&head, &stack_b, inf);
	if (ac == 6)
		five_nums(&head, &stack_b, inf);
	if (ac > 6)
		radix_sort(&head, &stack_b, ac - 1);
}
