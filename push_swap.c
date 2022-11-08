/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:54:30 by yomari            #+#    #+#             */
/*   Updated: 2022/11/08 19:06:43 by yomari           ###   ########.fr       */
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

void	three_nums(t_list **lst)
{
	int	a;
	int	b;
	int	c;

	a = (*lst)->content;
	b = (*lst)->next->content;
	c = (*lst)->next->next->content;
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

int	find_snumi(int *nums, int ac)
{
	int	tmp = nums[0];
	int	i = 0;
	int	c = 0;

	while (i < ac)
	{
		if (tmp <= nums[i])
		{
			tmp = nums[i];
			c++;
		}
		i++;
	}
	if (c  == ac)
		return(-1);
	i = 0;
	tmp = nums[i];
	while (i < ac)
	{
		if(tmp > nums[i])
			tmp = nums[i];
		i++;
	}
	i = 0;
	while (i < ac)
	{
		if ( tmp == nums[i])
			break;
		i++;
	}
	return (i);
}
void	for_nums(int *nums, t_list **st_a, t_list **st_b)
{
	int	i = find_snumi(nums, 4);

	if (i == -1)
		return;	
	else if (i == 0)
	{
		pb(st_a, st_b);
		write(1, "pb\n", 3);
		three_nums(st_a);
		pa(st_a, st_b);
		write(1, "pa\n", 3);
	}
	else if (i == 1)
	{
		ra(st_a);
		write(1, "ra\n", 3);
		pb(st_a, st_b);
		write(1, "pb\n", 3);
		three_nums(st_a);
		pa(st_a, st_b);
		write(1, "pa\n", 3);
	}
	else if (i == 2)
	{
		ra(st_a);
		write(1, "ra\n", 3);
		ra(st_a);
		write(1, "ra\n", 3);
		pb(st_a, st_b);
		write(1, "pb\n", 3);
		three_nums(st_a);
		pa(st_a, st_b);
		write(1, "pa\n", 3);
	}
	else if (i == 3)
	{
		rr(st_a);
		write(1, "rra\n", 4);
		pb(st_a, st_b);
		write(1, "pb\n", 3);
		three_nums(st_a);
		pa(st_a, st_b);
		write(1, "pa\n", 3);
	}
}

int	*fix_nums(int *nums, int i)
{
	int c = 0;
	int d = 0;
	int *nums1 = NULL;

	nums1 = malloc(sizeof(int) * 4);
	while(c < i)
	{
		nums1[c] = nums[d];
		c++;
		d++;
	}
	d++;
	while (c < 5)
	{
		nums1[c] = nums[d];
		c++;
		d++;
	}
	return (nums1);
}
void	five_nums(int *nums, t_list **st_a, t_list **st_b)
{
		int	i = find_snumi(nums, 5);

	if (i == 0)
	{
		pb(st_a, st_b);
		write(1, "pb\n", 3);
		for_nums(&nums[1], st_a, st_b);
		pa(st_a, st_b);
		write(1, "pa\n", 3);
	}
	else if (i == 1)
	{
		ra(st_a);
		write(1, "ra\n", 3);
		pb(st_a, st_b);
		write(1, "pb\n", 3);
		rr(st_a);
		write(1, "rra\n", 4);
		for_nums(fix_nums(nums, i), st_a, st_b);
		pa(st_a, st_b);
		write(1, "pa\n", 3);
	}
	else if (i == 2)
	{
		ra(st_a);
		write(1, "ra\n", 3);
		ra(st_a);
		write(1, "ra\n", 3);
		pb(st_a, st_b);
		write(1, "pb\n", 3);
		rr(st_a);
		write(1, "rra\n", 4);
		for_nums(fix_nums(nums, i), st_a, st_b);
		pa(st_a, st_b);
		write(1, "pa\n", 3);
	}
	else if (i == 3)
	{
		rr(st_a);
		write(1, "rra\n", 4);
		rr(st_a);
		write(1, "rra\n", 4);
		pb(st_a, st_b);
		write(1, "pb\n", 3);
		ra(st_a);
		write(1, "ra\n", 3);
		for_nums(fix_nums(nums, i), st_a, st_b);
		pa(st_a, st_b);
		write(1, "pa\n", 3);
	}
	else if (i == 4)
	{
		rr(st_a);
		write(1, "rra\n", 4);
		pb(st_a, st_b);
		write(1, "pb\n", 3);
		for_nums(fix_nums(nums, i), st_a, st_b);
		pa(st_a, st_b);
		write(1, "pa\n", 3);
	}
	
}

void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}
int	indexes(int n, int *nm, int s)
{
	int	i;

	i = 0;
	while (s)
	{
		if (nm[i] == n)
			return(i);
		i++;
		s--;
	}
	return(i);
}
void	b_sort(int	sz, int *nm)
{
	int	i;
	int	j;

	i = 0;
	while (i < sz - 1)
	{
		j = 0;
		while (j < sz - i -1)
		{
			if (nm[j] > nm [j + 1])
				swap(&nm[j], &nm[j + 1]);
			j++;
		}
		i++;
	}
}
void	convert_nums(t_list **lst, int *nm, int sz)
{
	t_list *tmp;

	tmp = *lst;

	while (tmp)
	{
		tmp->content = indexes(tmp->content, nm, sz);
		tmp = tmp->next;
	}
}
int	how_many_bits(int n)
{
	int	i;

	i = 0;
	while (n >> i )
		i++;
	return(i);
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
		while (sz)
		{
			//printls(*stack_a);
			nb = (*stack_a)->content;
			if(((nb >> i) & 1) == 1)
			{
				ra(stack_a);
				write(1, "ra\n", 3);
			}
			else
			{
				pb(stack_a, stack_b);
				write(1, "pb\n", 3);
			}
			sz--;
		}
		//printls(*stack_b);
		while(*stack_b != NULL)
		{
			pa(stack_a, stack_b);
			write(1, "pa\n", 3);
		}
		write(1, "wah\n", 4);
		i++;
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
		three_nums(&head);
	if (ac == 5)
		for_nums(nb, &head, &stack_b);
	if (ac == 6)
		five_nums(nb, &head, &stack_b);
	if (ac > 6)
	{
		b_sort(j, nb);
		convert_nums(&head, nb, j);
       printls(head);
		radix_sort(&head, &stack_b, ac - 1);
	}
		
     //  printls(head);
	
	//printf("%d //\n", find_snumi(nb,(ac - 1)));
	nb = NULL;
	free(nb);
}
