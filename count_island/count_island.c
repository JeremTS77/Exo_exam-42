/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 11:46:02 by jelefebv          #+#    #+#             */
/*   Updated: 2015/04/29 11:55:12 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void	count_island(char **i, int x, int y, char c);
void	sefsrg(char **i);
char	**cread(int fd);

void		count_island(char **i, int x, int y, char c)
{
	if (y < 0 || x < 0 || !i[y] || !i[y][x] || i[y][x] != 'X')
		return ;
	i[y][x] = c;
	count_island(i, x + 1, y, c);
	count_island(i, x - 1, y, c);
	count_island(i, x, y + 1, c);
	count_island(i, x, y - 1, c);
}

void		sefsrg(char **i)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	c = '0';
	while (i[y])
	{
		x = 0;
		while (i[y][x])
		{
			if (i[y][x] == 'X')
				count_island(i, x, y, c++);
			write(1, i[y] + x, 1);
			x++;
		}
		y++;
		if (x > 0)
			write(1, "\n", 1);
	}
}

int			read_first_line(int fd, char **r)
{
	int		i = 0;

	r[0] = malloc(sizeof(char) * 1300);
	while (read(fd, r[0] + i, 1) > 0)
	{
		if (r[0][i] == '\n')
		{
			r[0][i] = 0;
			return (i);
		}
		else if (r[0][i] != '.' && r[0][i] != 'X')
			return (-1);
		i++;
	}
	return (-1);
}

int			read_one_line(int fd, int len, char **r)
{
	int		readed;

	*r = malloc(sizeof(char) * (len + 10));
	readed = read(fd, *r, len + 1);
	if (readed == -1)
		return (-1);
	if (readed == 0)
		return (0);
	if (readed == 1 && **r == '\n')
	{
		**r = 0;
		return (0);
	}
	if (readed < len)
		return (-1);
	if (r[0][len] != '\n')
		return (-1);
	r[0][len] = 0;
	readed -= 2;
	while (readed >= 0)
	{
		if (r[0][readed] != 'X' && r[0][readed] != '.')
			return (-1);
		readed--;
	}
	return (1);
}

char		**cread(int fd)
{
	char	**result;
	int		i;
	int		linelen;
	int		ret;

	result = malloc(sizeof(char *) * 100000);
	i = 0;
	linelen = read_first_line(fd, result);
	if (linelen < 1)
		return (0);
	i++;
	while (1)
	{
		ret = read_one_line(fd, linelen, result + i);
		if (ret == -1)
			return (0);
		if (ret == 0)
			break ;
		i++;
	}
	return (result);
}

int		main(int ac, char **av)
{
	int		fd;
	char	**a;

	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd != -1)
		{
			a = cread(fd);
			close(fd);
			if (a != 0)
			{
				sefsrg(a);
				return (0);
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
