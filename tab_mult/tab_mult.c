/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 15:46:32 by jelefebv          #+#    #+#             */
/*   Updated: 2015/04/23 15:46:53 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);

int		ft_atoi(char *str)
{
	int		index;
	int		result;

	index = 0;
	result = 0;
	while (str[index] != '\0')
	{
		result = result * 10 + str[index] - '0';
		index++;
	}
	return (result);
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(str[index]);
		index = index + 1;
	}
}

int		main(int argc, char **argv)
{
	int		nb;
	int		calc;
	int		compteur;

	nb = 0;
	calc = 0;
	compteur = 1;
	if (argc >= 2)
	{
		nb = ft_atoi(argv[1]);
		while (compteur <= 9)
		{
			ft_putnbr(compteur);
			ft_putstr(" x ");
			ft_putstr(argv[1]);
			ft_putstr(" = ");
			calc = compteur * nb;
			ft_putnbr(calc);
			ft_putchar('\n');
			compteur++;
		}
		return (0);
	}
	ft_putchar('\n');
	return (0);
}
