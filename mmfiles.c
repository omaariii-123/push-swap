#include"push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int num;

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
	int neg;
	int num;
	int i;
	int	j;

	i = 0;
	neg = 1;
	num = 0;
	j = 0;

	while (str[j])
		j++;
	while (str[i] <= ' ')
		i++;
	if (i == j)
		exit(1);
		
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			neg *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
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
	write(1, "rra\n", 4);
}


