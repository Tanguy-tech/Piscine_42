/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 10:17:49 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/29 20:03:53 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_count_char(char *in, int *nb_chars_max)
{
	int		nb_lines;
	int		nb_chars;
	int		i;

	nb_lines = 0;
	nb_chars = 0;
	i = -1;
	while (in[++i])
	{
		if (in[i] != '\n')
		{
			nb_chars++;
		}
		else
		{
			nb_lines++;
			if (nb_chars > *nb_chars_max)
				*nb_chars_max = nb_chars;
			nb_chars = 0;
		}
	}
	return (nb_lines);
}

void	ft_map_generator(char *in, char **map, int *nb_chars)
{
	int i;
	int x;
	int y;

	x = -1;
	y = 0;
	i = -1;
	while (in[++i])
		if (in[i] == '\n' || i == 0)
		{
			map[++x] = malloc(sizeof(char) * (*nb_chars + 1));
			map[x][*nb_chars] = '\0';
			y = 0;
		}
		else
			map[x][y++] = in[i];
}

char	**ft_file_to_tab(char *in, int *nb_lines, int *nb_chars)
{
	char	**map;

	*nb_lines = ft_count_char(in, nb_chars);
	map = malloc(sizeof(char *) * (*nb_lines + 1));
	map[*nb_lines] = 0;
	ft_map_generator(in, map, nb_chars);
	free(in);
	return (map);
}
