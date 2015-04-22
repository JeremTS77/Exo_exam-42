/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 12:41:00 by exam              #+#    #+#             */
/*   Updated: 2015/04/22 13:12:12 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORD_H
#define ORD_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar(char c);
char	*ft_strdup(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_count_space(char *str);
int		ft_strlen(char *str);
int		ft_get_ind_maxlen(char **av);
void	ft_print_tab(char **av);
char	**ft_order(char **av);
char	ft_to_lower(char c);

#endif
