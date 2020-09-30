/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 08:56:20 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/24 08:56:22 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	char	*temp;
	int		i;

	if (!(temp = malloc(sizeof(char) * ft_strlen(src) + 1)))
		exit(0);
	i = 0;
	while (src[i])
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*str_av;
	int				i;

	i = 0;
	if (!(str_av = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1))))
		return (0);
	while (i < ac)
	{
		str_av[i].size = ft_strlen(av[i]);
		str_av[i].str = av[i];
		str_av[i].copy = ft_strdup(av[i]);
		i++;
	}
	str_av[i].size = 0;
	str_av[i].str = 0;
	str_av[i].copy = 0;
	return (str_av);
}
