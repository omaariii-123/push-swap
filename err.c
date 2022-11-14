#include"push_swap.h"

void	p_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_is_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	check_error(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_is_digit(av[i][j]) == 1)
				j++;
			else if (av[i][j] == 45 || av[i][j] == 43)
			{
				if(ft_is_digit(av[i][j + 1]) == 1)
					j++;
				else
					p_error();
			}
			else
				p_error();
		}
		i++;
	}
}
