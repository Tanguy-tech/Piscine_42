/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:53:00 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/30 23:22:12 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		check_line_len(char **map, int nb_lines, int nb_chars)
{
	int i;
	int line_len;

	i = 1;
	line_len = nb_chars;
	if (ft_strlen(map[0]) < 4)
		return (0);
	if (line_len < 1)
		return (0);
	while (i < nb_lines)
	{
		if (line_len != ft_strlen(map[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		check_lines_nb(char **map, int nb_lines)
{
	char	*params;
	int		lines_comp;

	params = cat_first_params(map);
	lines_comp = ft_atoi(params);
	if (nb_lines - 1 != lines_comp)
		return (0);
	return (1);
}
