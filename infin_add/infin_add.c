/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 11:30:00 by jelefebv          #+#    #+#             */
/*   Updated: 2015/04/29 11:36:58 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		compare(char *a, char *b)
{
	int		lena;
	int		lenb;
	int		i;

	lena = ft_strlen(a);
	lenb = ft_strlen(b);
	if (lena > lenb)
		return (1);
	else if (lenb > lena)
		return (-1);
	i = 0;
	while (i < lena)
	{
		if (a[i] > b[i])
			return (1);
		if (b[i] > a[i])
			return (-1);
		i++;
	}
	return (0);
}

char	*add(char *a, char *b)
{
	char	*out;
	int		lena;
	int		lenb;
	int		len;
	int		i;
	int		rest;

	len = 0;
	i = 0;
	rest = 0;
	lena = ft_strlen(a);
	lenb = ft_strlen(b);
	if (lena >= lenb)
		len = lena + 1;
	else if (lenb > lena)
		len = lenb + 1;
	out = (char *)malloc(len + 1);
	out[0] = '0';
	out[len] = 0;
	while (i < lena || i < lenb || rest)
	{
		if (i >= lena && i >= lenb)
		{
			out[len - i - 1] = rest % 10 + '0';
			rest = rest / 10;
		}
		else if (i >= lena)
		{
			out[len - i - 1] = (rest + b[lenb - i - 1] - '0') % 10 + '0';
			rest = (rest + b[lenb - i - 1] - '0') / 10;
		}
		else if (i >= lenb)
		{
			out[len - i - 1] = (rest + a[lena - i - 1] - '0') % 10 + '0';
			rest = (rest + a[lena - i - 1] - '0') / 10;
		}
		else
		{
			out[len - i - 1] = (rest + a[lena - i - 1] - '0' + b[lenb - i - 1] - '0') % 10 + '0';
			rest = (rest + a[lena - i - 1] - '0' + b[lenb - i - 1] - '0') / 10;
		}
		i++;
	}
	return (out + len - i);
}

char	*substract(char *a, char *b)
{
	char	*out;
	int		lena;
	int		lenb;
	int		len;
	int		i;
	int		rest;

	len = 0;
	i = 0;
	rest = 0;
	lena = ft_strlen(a);
	lenb = ft_strlen(b);
	if (lena >= lenb)
		len = lena;
	else if (lenb > lena)
		len = lenb;
	out = (char *)malloc(len + 1);
	out[len] = 0;
	while (i < lena || i < lenb)
	{
		if (i >= lena)
		{
			out[len - i - 1] = ((b[lenb - i - 1] - '0') - rest + 10) % 10 + '0';
			rest = (b[lenb - i - 1] - '0' - rest) < 0;
		}
		else if (i >= lenb)
		{
			out[len - i - 1] = ((a[lena - i - 1] - '0') - rest + 10) % 10 + '0';
			rest = (a[lena - i - 1] - '0' - rest) < 0;
		}
		else
		{
			out[len - i - 1] = ((a[lena - i - 1] - '0') - (b[lenb - i - 1] - '0') - rest + 10) % 10 + '0';
			rest = ((a[lena - i - 1] - '0') - (b[lenb - i - 1] - '0') - rest) < 0;
		}
		i++;
	}
	out = out + len - i;
	while (out[0] == '0')
		out++;
	return (out);
}

int		main(int argc, char **argv)
{
	char	*res;
	int		comp;

	if (argc != 3)
		return (0);
	if (argv[1][0] != '-' && argv[2][0] != '-')
		res = add(argv[1], argv[2]);
	else if (argv[1][0] == '-' && argv[2][0] == '-')
	{
		ft_putchar('-');
		res = add(argv[1] + 1, argv[2] + 1);
	}
	else
	{
		if (argv[1][0] == '-')
		{
			comp = compare(argv[1] + 1, argv[2]);
			if (comp > 0)
			{
				ft_putchar('-');
				res = substract(argv[1] + 1, argv[2]);
			}
			else if (comp < 0)
				res = substract(argv[2], argv[1] + 1);
			else
				res = "0";
		}
		else
		{
			comp = compare(argv[1], argv[2] + 1);
			if (comp > 0)
				res = substract(argv[1], argv[2] + 1);
			else if (comp < 0)
			{
				ft_putchar('-');
				res = substract(argv[2] + 1, argv[1]);
			}
			else
				res = "0";
		}
	}
	write(1, res, ft_strlen(res));
	ft_putchar('\n');
	return (0);
}
