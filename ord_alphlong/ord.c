/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 10:20:26 by exam              #+#    #+#             */
/*   Updated: 2015/04/22 13:11:53 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	ft_to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	else
		return (c);
}

char	*ft_strdup(char *str)
{
	char	*ret;
	int		i;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	while (str[i])
	{
		ret[i] = str[i];
		++i;
	}
	ret[i] = '\0';
	return (ret);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && (s2[i] == s1[i] || s2[i] == (s1[i] - 32) || (s2[i] - 32) == s1[i]))
	{
		++i;
	}
	return (ft_to_lower(s1[i]) - ft_to_lower(s2[i]));
}

int		ft_count_space(char *str)
{
	int	space;

	space = 1;
	if (!str || !*str)
		return (0);
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
			++space;
		++str;
	}
	return (space);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}

int		ft_get_ind_maxlen(char **av)
{
	int	index;
	int ret;
	int cmp;

	index = 0;
	ret = 0;
	cmp = 0;
	while (av[index] != NULL)
	{
		ret = ((cmp = ft_strlen(av[index])) > ret) ? cmp : ret;
		++index;
	}
	return (ret);
}

void	ft_print_tab(char **av)
{
	int	yolo;
	int	check;
	int	maxlen;
	int	len;

	yolo = 0;
	check = 0;
	len = 1;
	maxlen = ft_get_ind_maxlen(av);
	while (len <= maxlen)
	{
		check = 0;
		while (av[yolo] != NULL)
		{
			if (ft_strlen(av[yolo]) == len)
			{
				if (check == 1)
				{
					ft_putchar(' ');
					check = 0;
				}
				write(1, av[yolo], len);
				check = 1;
			}
			++yolo;
		}
		if (check == 1)
			ft_putchar('\n');
		yolo = 0;
		++len;
	}
}

char	**ft_order(char **av)
{
	int		index;
	char	*tmp;

	index = 0;
	while (av[index + 1] != NULL)
	{
		if (ft_strcmp(av[index], av[index + 1]) > 0)
		{
			tmp = ft_strdup(av[index]);
			av[index] = ft_strdup(av[index + 1]);
			av[index + 1] = ft_strdup(tmp);
			index = 0;
		}
		else
			index++;
	}
	return (av);
}

int		main(int ac, char **av)
{
	int yolo;
	int	yoloindex;
	int	index;
	char **split;

	yolo = 0;
	yoloindex = 0;
	index = 0;
	if (ac == 2)
	{
		if (!av[1] || !av[1][index])
		{
			ft_putchar('\n');
			return (0);
		}
		if (!(split = (char **)malloc(sizeof(char *) * ft_count_space(av[1]) + 1)))
			return (0);
		if (!(split[yolo] = (char *)malloc(sizeof(char) * ft_strlen(av[1]) + 1)))
			return (0);
		while (av[1][index])
		{
			if (av[1][index] == ' ' || av[1][index] == '\t')
			{
				while (av[1][index] && (av[1][index] == ' ' || av[1][index] == '\t'))
					++index;
				split[yolo][yoloindex] = '\0';
				++yolo;
				yoloindex = 0;
				if (!(split[yolo] = (char *)malloc(sizeof(char) * ft_strlen(av[1]) + 1)))
					return (0);
			}
			else
			{
				split[yolo][yoloindex] = av[1][index];
				++yoloindex;
				++index;
			}
		}
		split[yolo][yoloindex] = '\0';
		++yolo;
		split[yolo] = NULL;
		split = ft_order(split);
		ft_print_tab(split);
	}
	else
		ft_putchar('\n');
	return (0);
}
