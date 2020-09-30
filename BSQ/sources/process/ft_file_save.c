/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_save.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:06:54 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/29 20:00:01 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h" 

char	**ft_file_save(char *name_file)
{
	int		fd;
	char	**map;
	int		i;
	int		j;
	char	c;

	if ((fd = open(name_file, O_RDONLY)) == -1)
		return (0);
	if ((map = malloc(sizeof(char *) * 100 + 1)) == NULL)
		return (0);
	map[100] = 0;
	i = 0;
	j = 0;
	if ((map[i] = malloc(sizeof(char) * 2000 + 1)) == NULL)
		return (0);
	map[i][2000] = '\0';
	while (read(fd, &c, 1) > 0)
	{
		map[i][j++] = c;
		if (j == 1999)
		{
			if ((map[++i] = malloc(sizeof(char) * 2000 + 1)) == NULL)
				return (0);
			j = 0;
		}
		map[i + 1] = 0;
		map[i][j] = '\0';
	}
	return (map);
}
