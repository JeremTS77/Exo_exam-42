/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 09:49:10 by exam              #+#    #+#             */
/*   Updated: 2015/03/05 10:54:15 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_str(char *str, int check)
{
	int		index;

	index = 0;
	if (str != NULL)
	{
		while (str[index] != '\0')
		{
			if (check == 1)
				ft_putchar(str[index]);
			index++;
		}
	}
	return (index);
}

int		ft_strcountspace(char *s)
{
	int		i;

	i = 1;
	while (*s)
	{
		if (*s == ' ' || *s == '\t')
			i++;
		s++;
	}
	return (i);
}

char	**ft_strsplit(char *s, int i)
{
	int		j;
	int		count;
	char	**split;

	j = 0;
	count = 0;
	if (!(split = (char **)malloc(sizeof(char *) * i + 1)))
		return (NULL);
	if (!(split[j] = (char *)malloc(sizeof(char) * ft_str(s, 0) + 1)))
		return (NULL);
	split[i] = NULL;
	while (*s)
	{
		if (*s == ' ' || *s == '\t')
		{
			split[j++][count] = '\0';
			count = 0;
			s++;
			if (!(split[j] = (char *)malloc(sizeof(char) * ft_str(s, 0) + 1)))
				return (NULL);
		}
		split[j][count++] = *s++;
	}
	split[j][count] = '\0';
	return (split);
}

int		main(int ac, char **av)
{
	int		i;
	int		keep;
	char	**split;

	if (ac == 2)
	{
		i = ft_strcountspace(av[1]);
		keep = i;
		split = ft_strsplit(av[1], i);
		while ((i + 1) != 0)
		{
			if (i == 0 || i == keep)
				ft_str(split[i--], 1);
			else
			{
				ft_str(split[i--], 1);
				ft_putchar(' ');
			}
		}
	}
	ft_putchar('\n');
	return (0);
}
