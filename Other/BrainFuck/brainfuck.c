/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 10:28:42 by jelefebv          #+#    #+#             */
/*   Updated: 2015/04/29 10:30:16 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BF_INC '>'
#define BF_DEC '<'
#define BF_ADD '+'
#define BF_SUB '-'
#define BF_OUT '.'
#define BF_STT '['
#define BF_END ']'

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>

void	*ft_memset(void *mem, int val, size_t size)
{
	uint8_t			*cmem;
	uint8_t			cval;
	size_t			i;

	cmem = (uint8_t *)mem;
	cval = (uint8_t)val;
	i = 0;
	while (i < size)
	{
		cmem[i] = cval;
		++i;
	}
	return (mem);
}

void	brainfuck(char *prog)
{
	uint8_t				*mem;
	uint8_t				*ptr;
	int					stack;
	int					i;

	mem = (uint8_t *)malloc(sizeof(uint8_t) * 2048);
	if (mem == NULL)
		return ;
	ft_memset(mem, 0, sizeof(uint8_t) * 2048);
	ptr = mem;
	i = 0;
	while (prog[i])
	{
		if (prog[i] == BF_INC)
			++ptr;
		else if (prog[i] == BF_DEC)
			--ptr;
		else if (prog[i] == BF_ADD)
			++(*ptr);
		else if (prog[i] == BF_SUB)
			--(*ptr);
		else if (prog[i] == BF_OUT)
			write(1, ptr, 1);
		else if (prog[i] == BF_STT)
		{
			if (*ptr == 0)
			{
				stack = 0;
				while (prog[i])
				{
					if (prog[i] == BF_STT)
					{
						++stack;
					}
					else if (prog[i] == BF_END)
					{
						if (stack)
							--stack;
						if (stack == 0)
							break ;
					}
					++i;
				}
			}
		}
		else if (prog[i] == BF_END)
		{
			if (*ptr != 0)
			{
				stack = 0;
				while (i >= 0)
				{
					if (prog[i] == BF_END)
					{
						++stack;
					}
					else if (prog[i] == BF_STT)
					{
						if (stack)
							--stack;
						if (stack == 0)
							break ;
					}
					--i;
				}
			}
		}
		++i;
	}
}

int		main(int c, char **v)
{
	if (c < 2) {
		write(1, "\n", 1);
		return (0);
	}
	brainfuck(v[1]);
	return (0);
}
