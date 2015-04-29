/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 11:05:40 by jelefebv          #+#    #+#             */
/*   Updated: 2015/04/29 11:05:44 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int		main(void)
{
	int		fd;
	int		nbr;

	nbr = 0;
	while (1)
	{
		fd = open("/tmp/asiat_racer", O_RDONLY);
		if (fd == 3)
		{
			read(fd, &nbr, sizeof(int));
			printf("%d\n", nbr);
			return (nbr);
		}
	}
	return (0);
}
