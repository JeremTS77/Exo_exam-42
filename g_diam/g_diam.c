/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_diam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 12:06:32 by jelefebv          #+#    #+#             */
/*   Updated: 2015/04/29 12:14:14 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putnbr(int i);
void	remove_all_occur(char *base, char *node);
int		recur(char *base, char *node);
void	try_call(char *what, char *par, char *cn, int *max);
int		g_diam(char *a);
char	*ft_strdup(char *src);
int		intcmp(char *a, char *b);
int		ft_strlen(char *str);

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i] != '\0')
		++i;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		index;

	index = 0;
	if (!(dest = (char *)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return ((void *)0);
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

int		intcmp(char *a, char *b)
{
	while (*a == *b)
	{
		if (*a > '9' || *a < '0')
			return (1);
		a++;
		b++;
	}
	return ((*a > '9' || *a < '0') && (*b < '0' || *b > '9'));
}

void	ft_putnbr(int i)
{
	char	c;

	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
	{
		c = '0' + i;
		write(1, &c, 1);
	}
}

void	remove_all_occur(char *base, char *node)
{
	int		x;
	int		y;

	x = 0;
	while (base[x])
	{
		while (base[x] == ' ')
			x++;
		if (!base[x])
			return ;
		y = 0;
		while (base[x + y] != '-')
			y++;
		if (intcmp(base + x, node) || intcmp(base + x + y + 1, node))
			while (base[x] != ' ' && base[x])
				base[x++] = ' ';
		else
			while (base[x] != ' ' && base[x])
				x++;
	}
}

void	try_call(char *what, char *par, char *cn, int *max)
{
	int		i;
	int		mma;

	mma = 0;
	i = 0;
	while (what[i] != '-')
		i++;
	i++;
	if (intcmp(cn, what))
		mma = recur(par, what + i);
	else if (intcmp(cn, what + i))
		mma = recur(par, what);
	if (mma > *max)
		*max = mma;
}

int		recur(char *base, char *node)
{
	int		i;
	char	*str;
	int		max;

	str = ft_strdup(base);
	remove_all_occur(str, node);
	i = 0;
	max = 0;
	while (base[i])
	{
		while (base[i] == ' ')
			i++;
		if (!base[i])
			break ;
		try_call(base + i, str, node, &max);
		while (base[i] && base[i] != ' ')
			i++;
	}
	free(str);
	return (max + 1);
}

int		g_diam(char *a)
{
	int		i;
	int		y;
	int		max;
	int		ac;

	i = 0;
	max = 0;
	while (a[i])
	{
		y = 0;
		while (a[i + y] != '-')
			y++;
		y++;
		ac = recur(a, a + i);
		if (ac > max)
			max = ac;
		ac = recur(a, a + i + y);
		if (ac > max)
			max = ac;
		while (a[i] && a[i] != ' ')
			i++;
		if (a[i])
			i++;
	}
	return (max);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_putnbr(g_diam(av[1]));
	write(1, "\n", 1);
	return (0);
}
