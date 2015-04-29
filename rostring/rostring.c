/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smignard <smignard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 15:52:02 by smignard          #+#    #+#             */
/*   Updated: 2015/04/23 17:02:08 by smignard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define ft_isspace(c) ((c) == ' ' || (c) == '\t')

int        ft_strlen(char *str)
{
	char    *ptr;

	ptr = str;
	while (*ptr)
		ptr++;
	return (ptr - str);
}

void    rostring(char *str)
{
	char    *new;
	int        first, first_end;
	int        word;
	int        i;

	new = malloc(ft_strlen(str));

	i = 0;
	word = -1;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
		{
			first = i;
			while (str[i] && !ft_isspace(str[i]))
				++i;
			first_end = i;
			break ;
		}
		++i;
	}
	while (str[i])
	{
		if (!ft_isspace(str[i]))
		{
			if (word != -1)
				write(1, " ", 1);
			word = i;
			while (str[i] && !ft_isspace(str[i]))
				++i;
			write(1, &str[word], i - word);
			continue ;
		}
		++i;
	}
	if (word != -1)
		write(1, " ", 1);
	write(1, &str[first], first_end - first);
}



int        main(int c, char **v)
{
	if (c > 1)
		rostring(v[1]);
	write(1, "\n", 1);
	return (0);
}
