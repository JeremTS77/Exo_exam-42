/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 09:41:36 by exam              #+#    #+#             */
/*   Updated: 2015/04/22 09:48:41 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while(av[1][i])
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
			{
				if (av[1][i] == 'z')
					ft_putchar('a');
				else
					ft_putchar(av[1][i] + 1);
			}
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				if (av[1][i] == 'Z')
					ft_putchar('A');
				else
					ft_putchar(av[1][i] + 1);
			}
			else
				ft_putchar(av[1][i]);
			++i;
		}
	}
	ft_putchar('\n');
	return (0);
}
