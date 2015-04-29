/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 10:43:13 by jelefebv          #+#    #+#             */
/*   Updated: 2015/04/29 10:43:14 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		max(int *tab, unsigned int len)
{
	unsigned int	cmp;
	int				cpy;

	cmp = 0;
	cpy = tab[0];
	while (cmp < len)
	{
		if (cpy < tab[cmp])
			cpy = tab[cmp];
		++cmp;
	}
	if (cmp == len)
		return (cpy);
	return (0);
}
