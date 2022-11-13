#include"push_swap.h"

void	s(t_list **lst, char *str)
{
	int		tmp;
	t_list	*new;

	new = NULL;
	tmp = (*lst)->content;
	*lst = delete_fnode(*lst);
	new = ft_lstnew(tmp);
	new->next = (*lst)->next;
	(*lst)->next = new;
	write(1, str, 3);
}

void	p(t_list **stack_b, t_list **stack_a, char *str)
{
	int	i;

	i = (*stack_a)->content;
	*stack_a = delete_fnode(*stack_a);
	ft_lstadd_front (stack_b, ft_lstnew(i));
	write(1, str, 3);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	p(stack_a, stack_b, "pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	p(stack_b, stack_a, "pb\n");
}

void	ra(t_list **lst)
{
	int	tmp;

	tmp = (*lst)->content;
	*lst = delete_fnode(*lst);
	ft_lstadd_back(lst, ft_lstnew(tmp));
	write(1, "ra\n", 3);
}
