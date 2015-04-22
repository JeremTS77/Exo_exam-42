/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_first_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 09:29:10 by exam              #+#    #+#             */
/*   Updated: 2015/04/01 09:34:41 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int	main(int ac, char **av)
{
	int	c;

	c = 0;
	if (ac >= 2)
	{
		write(1, av[1], ft_strlen(av[1]));
	}
	write(1, "\n", 1);
	return (0);
}
