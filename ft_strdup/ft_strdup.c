/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 09:43:02 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 09:53:12 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int n;

	n = 0;
	if (str)
		while (str[n] != '\0')
			++n;
	return (n);
}

char	*ft_strdup(char *src)
{
	char		*dest;
	int		index;

	index = 0;
	if (!(dest = (char *)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return ((void *)0);
	while (src[index])
	{
		dest[index] = src[index];
		++index;
	}
	dest[index] = '\0';
	return (dest);
}
