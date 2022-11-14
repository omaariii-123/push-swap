#include"push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	num;

	num = nb;
	if (num < 0)
	{
		num *= -1;
		ft_putchar('-');
	}
	if (num > 9)
	{
		ft_putnbr(num / 10);
	}
	ft_putchar(num % 10 + 48);
}

int	ft_atoi(char *str)
{
	int	neg;
	long	num;
	int	i;

	i = 0;
	num = 0;
	while (str[i] <= ' ')
		i++;
	neg = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - 48);
	if (num > 2147483647 && neg > 0)
		p_error();
	else if ((num * neg) < -2147483648)
		p_error();
	return (num * neg);
}

void	check_double(t_list *lst, int *nums, int nb)
{
	int	i;
	int	n;
	int	c;

	while (lst)
	{
		n = nb;
		c = 0;
		i = 0;
		while (n)
		{
			if (lst->content == nums[i])
				c++;
			n--;
			i++;
		}
		if (c > 1)
			p_error();
		lst = lst->next;
	}
}

void	rr(t_list **lst)
{
	t_list	*tmp;
	int		i;

	tmp = NULL;
	tmp = *lst;
	while (tmp->next->next)
		tmp = tmp->next;
	i = tmp->next->content;
	free(tmp->next);
	tmp->next = NULL;
	ft_lstadd_front(lst, ft_lstnew(i));
	write(1, "rra\n", 4);
}
