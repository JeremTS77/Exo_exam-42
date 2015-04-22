/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 09:36:48 by exam              #+#    #+#             */
/*   Updated: 2015/03/05 09:46:53 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int		main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ac == 3)
	{
		while (av[2][i] != '\0')
		{
			if (av[1][j] == '\0')
			{
				ft_putstr(av[1]);
				ft_putchar('\n');
				return (0);
			}
			if (av[2][i] == av[1][j])
				j++;
			i++;
		}
		if (av[1][j] == '\0')
			ft_putstr(av[1]);
	}
	ft_putchar('\n');
	return (0);
}
