/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 09:50:56 by jelefebv          #+#    #+#             */
/*   Updated: 2015/04/29 09:51:59 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(48 + nb);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	print_invalid(void)
{
	write(1, "0\n", 2);
}

int		add(int a, int b)
{
	return (a + b);
}

int		sub(int a, int b)
{
	return (a - b);
}

int		mult(int a, int b)
{
	return (a * b);
}

int		div(int a, int b)
{
	return (a / b);
}

int		mod(int a, int b)
{
	return (a % b);
}
int		is_numeric_char(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c == '-' || c == '+')
		return (1);
	else
		return (0);
}

int		my_little_atoi(char *str)
{
	int	i;
	int	negative_flag;
	int	result;

	i = 0;
	negative_flag = 0;
	result = 0;
	while ((str[i] != '\0') && (is_numeric_char(str[i])))
	{
		result *= 10;
		if (str[i] == '-' && !(negative_flag))
			negative_flag = 1;
		if (str[i] >= '0' && str[i] <= '9')
			result += str[i] - '0';
		i++;
	}
	if (negative_flag)
		return (result * -1);
	return (result);
}

int		doop(char op, int nb1, int nb2)
{
	int		result;
	int		i;
	int		(*opfunc[5])(int, int) = { &add, &sub, &mult, &div, &mod};
	char	operators[5] = { '+', '-', '*', '/', '%' };

	result = 0;
	i = 0;
	while (i < 5)
	{
		if (operators[i] == op)
		{
			result = opfunc[i](nb1, nb2);
			break ;
		}
		i++;
	}
	return (result);
}

int		main(int argc, char **argv)
{
	int	nb1;
	int	nb2;
	int	result;

	if (argc == 4)
	{
		if (!argv[1] || !*argv[1] || !argv[2] || !*argv[2] || !argv[3] || !*argv[3])
		{
			ft_putchar('\n');
			return (0);
		}
		nb1 = my_little_atoi(argv[1]);
		nb2 = my_little_atoi(argv[3]);
		if ((argv[2][0] == '/') && !(nb2))
			ft_putstr("Stop : division by zero\n");
		else if ((argv[2][0] == '%') && !(nb2))
			ft_putstr("Stop : modulo by zero\n");
		else
		{
			result = doop(argv[2][0], nb1, nb2);
			ft_putnbr(result);
			ft_putchar('\n');
		}
	}
	return (0);
}
