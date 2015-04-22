/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 09:36:50 by exam              #+#    #+#             */
/*   Updated: 2015/04/01 09:59:52 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i])
		++i;
	return (i);
}

char *ft_strrev(char *str)
{
	int		pos;
	int		index;
	char	tmp[ft_strlen(str)];

	pos = 0;
	index = 0;
	if (!str || !*str)
		return (str);
	while (str[index] != '\0')
	{
		tmp[index] = str[index];
		++index;
	}
	pos = index - 1;
	index = 0;
	while (index != pos + 1)
	{
		str[index] = tmp[pos - index];
		++index;
	}
	return (str);
}
