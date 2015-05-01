/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/16 15:73:10 by jelefebv          #+#    #+#             */
/*   Updated: 2015/05/01 17:50:35 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void			ft_putchar(char c);

static int		print_door(int level, int *stage, int base, int tmp)
{
	int		door_size;

	door_size = (stage[0] % 2) ? stage[0] : (stage[0] - 1);
	if ((stage[0] == stage[1]) && (level < door_size)
		&& (tmp >= ((base + 1) / 2) - (door_size / 2))
		&& (tmp <= ((base + 1) / 2) + (door_size / 2)))
	{
		if ((stage[0] >= 5) && (level == ((door_size / 2)))
			&& (tmp == ((base / 2) - (door_size / 2) + 2)))
			ft_putchar('$');
		else
			ft_putchar('|');
		return (1);
	}
	else
		return (0);
}

static void		print_base(int sizeline, int line, int many, int *stage)
{
	int		tmp;
	int		base;
	int		level;

	stage[1]++;
	base = sizeline - (many * 2) + 2;
	while (many--)
	{
		tmp = line - base / 2;
		level = tmp;
		while (tmp-- > 0)
			ft_putchar(' ');
		tmp = base;
		ft_putchar('/');
		while (tmp-- > 2)
		{
			if (!print_door(level, stage, base, tmp))
				ft_putchar('*');
		}
		ft_putchar('\\');
		ft_putchar('\n');
		base += 2;
	}
}

static void		print_stage(int cursize, int line, int curline, int *stage)
{
	if (cursize < 3)
		return ;
	print_stage(cursize - 1, line, curline - cursize - (cursize) / 2, stage);
	print_base(curline * 2 + 1, line, cursize, stage);
}

void			sastantua(int size)
{
	int		halfline;
	int		tmp;
	int		cur;
	int		stage[2];

	if (size < 1)
		return ;
	stage[0] = size;
	stage[1] = 0;
	tmp = size + 2;
	halfline = (tmp + 1) / -2;
	while (tmp >= 3)
	{
		cur = tmp;
		halfline += cur + (cur + 1) / 2;
		while (cur > 0)
			--cur;
		--tmp;
	}
	print_stage(size + 2, halfline, halfline, stage);
}

int				ft_atoi(char *str)
{
	int		result;
	int		index;
	int		signe;

	result = 0;
	index = 0;
	signe = 1;
	while (str[index] != '\0')
	{
		if (str[index] == '-')
			signe = signe * -1;
		else if ((str[index] < '0' || str[index] > '9'))
			return (0);
		else
			result = result * 10 + (str[index] - '0');
		index = index + 1;
	}
	return (result * signe);
}

int				main(int argc, char **argv)
{
	if (argc == 2)
		sastantua(ft_atoi(argv[1]));
	return (0);
}
