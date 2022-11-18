/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 04:08:31 by yomari            #+#    #+#             */
/*   Updated: 2022/11/14 22:13:50 by yomari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>

typedef struct t_list{
	int				content;
	struct t_list	*next;

}t_list;

typedef struct t_info
{
	int	zero;
	int	one;
}t_info;

t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *list);
t_list	*delete_fnode(t_list *list);
t_list	*ft_last(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *nnew);
void	ft_lstadd_back(t_list **lst, t_list *nnew);
void	swap(int *x, int *y);
int		indexes(int n, int *nm, int s);
void	b_sort(int sz, int *nm);
void	convert_nums(t_list **lst, int *nm, int sz, t_info *inf);
int		how_many_bits(int n);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
void	check_double(t_list *lst, int *nums, int nb);
void	rr(t_list **lst);
void	s(t_list **lst, char *str);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **lst);
void	two_nums(t_list **lst);
void	three_nums(t_list **lst);
void	four_nums(t_list **st_a, t_list **st_b, t_info inf);
void	five_nums(t_list **st_a, t_list **st_b, t_info inf);
void	check_error(char **av, int negation, int i);
void	p_error(void);
#endif
