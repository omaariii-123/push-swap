#include"push_swap.h"

void	swap(int *x, int *y)
{
	int	tmp;

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
			return (i);
		i++;
		s--;
	}
	return (i);
}

void	b_sort(int sz, int *nm)
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

void	convert_nums(t_list **lst, int *nm, int sz, t_info *inf)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *lst;
	while (tmp)
	{
		tmp->content = indexes(tmp->content, nm, sz);
		if (tmp->content == 0)
			inf->zero = i;
		else if (tmp->content == 1)
			inf->one = i;
		tmp = tmp->next;
		i++;
	}
}

int	how_many_bits(int n)
{
	int	i;

	i = 0;
	while (n >> i)
		i++;
	return (i);
}
