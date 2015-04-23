/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 17:23:24 by jelefebv          #+#    #+#             */
/*   Updated: 2015/04/23 17:26:31 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void		ftp(char c)
{
	write(1, &c, 1);
}

char		*ft_strnew(int i)
{
	char	*result;

	if (!(result = malloc(sizeof(char) * (i + 2))))
		return (0);
	i++;
	while (i)
		result[i--] = 0;
	return (result);
}

int			ft_strlen(char *c)
{
	int		i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char		multone(int *ret, char a, char b)
{
	a -= '0';
	b -= '0';

	a *= b;
	a += *ret;
	if (a > 9)
	{
		*ret = a / 10;
		a %= 10;
	}
	else
		*ret = 0;
	return (a + '0');
}

void		ft_addchar(char *a, char toa)
{
	int		i;

	i = ft_strlen(a);
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = toa;
}

char		*mult(char *a, char b)
{
	char	*result;
	int		i;
	int		ret;

	ret = 0;
	i = ft_strlen(a);
	result = ft_strnew(i + 1);
	while (--i >= 0)
	{
		ft_addchar(result, multone(&ret, a[i], b));
	}
	if (ret > 0)
		ft_addchar(result, ret + '0');
	return (result);
}

char		isn(char **av)
{
	char	isneg;

	isneg = 0;
	if (av[1][0] == '-')
	{
		if (av[2][0] != '-')
			isneg = 1;
		else
			av[2]++;
		av[1]++;
	}
	else if (av[2][0] == '-')
	{
		isneg = 1;
		av[2]++;
	}
	return (isneg);
}

char		**initmultval(char **av)
{
	int		i;
	char	**result;

	if (!(result = malloc(sizeof(char *) * 10)))
		return (0);
	i = 0;
	while (i < 10)
		result[i++] = 0;
	i = 0;
	while (av[2][i])
	{
		if (result[av[2][i] - '0'] == 0)
			result[av[2][i] - '0'] = mult(av[1], av[2][i]);
		i++;
	}
	return (result);
}

char		gcc(char *c, int i)
{
	i = ft_strlen(c) - i - 1;
	if (i < 0 || i >= ft_strlen(c))
		return (-1);
	return (c[i] - '0');
}

char		get_char(int *ret, char **multval, char *a, int i)
{
	int		boo;
	int		result;
	int		x;
	int		z;

	boo = 1;
	result = 0;
	x = ft_strlen(a) - 1;
	while (x >= 0)
	{
		z = gcc(multval[a[x] - '0'], i - (ft_strlen(a) - 1 - x));
		if (z != -1)
		{
			result += z;
			boo = 0;
		}
		x--;
	}
	if (*ret > 0)
		boo = 0;
	result += *ret;
	if (result > 9)
	{
		*ret = result / 10;
		result %= 10;
	}
	else
		*ret = 0;
	if (boo)
		return (-1);
	return (result + '0');
}

void		disp_number(char isneg, char *str)
{
	int		i;
	int		iszero;

	i = 0;
	iszero = 1;
	while (str[i])
	{
		if (str[i] != '0')
		{
			iszero = 0;
			break;
		}
		i++;
	}
	if (iszero)
		ftp('0');
	else
	{
		i = 0;
		if (isneg)
			ftp('-');
		while (str[i])
			ftp(str[i++]);
	}
	ftp('\n');
}

int			main(int ac, char **av)
{
	char	**multval;
	char	*result;
	char	isneg;
	int		i;
	int		ret;
	char	toadd;

	(void)ac;
	(void)isneg;
	isneg = isn(av);
	multval = initmultval(av);
	i = 0;
	result = ft_strnew(1000000);
	while (1)
	{
		toadd = get_char(&ret, multval, av[2], i);
		i++;
		if (toadd == -1)
			break;
		ft_addchar(result, toadd);
	}
	disp_number(isneg, result);
	return (0);
}
