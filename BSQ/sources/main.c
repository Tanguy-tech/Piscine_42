/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 20:12:57 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/30 23:33:15 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		main(int ac, char **av)
{
	char	**own_map;
	int		nb_line;
	int		nb_chars;

	av++;
	if (ac <= 1)
	{
		nb_line = 0;
		nb_chars = 0;
		own_map = ft_file_to_tab(ft_stdin_save(), &nb_line, &nb_chars);
		if (is_map_valid(own_map, nb_line, nb_chars) == 0)
			return (0);
		ft_process(own_map, &nb_line, &nb_chars);
	}
	if (ac >= 2)
	{
		while (*av)
		{
			nb_line = 0;
			nb_chars = 0;
			own_map = ft_file_to_tab(ft_file_save(*av), &nb_line, &nb_chars);
			if (is_map_valid(own_map, nb_line, nb_chars) == 0)
				return (0);
			ft_process(own_map, &nb_line, &nb_chars);
			ft_putchar('\n');
			av++;
		}
	}
}
