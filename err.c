/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:19:00 by yomari            #+#    #+#             */
/*   Updated: 2022/11/14 22:37:17 by yomari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	p_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_is_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	check_error(char **av, int negation, int i)
{
	int		j;

	while (av[i])
	{
		negation = 1;
		j = 0;
		while (av[i][j])
		{
			if (ft_is_digit(av[i][j]) == 1)
			{
				negation = 0;
				j++;
			}
			else if (negation && (av[i][j] == 45 || av[i][j] == 43))
			{
				negation = 0;
				if (ft_is_digit(av[i][j + 1]) == 1)
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
