/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:32:18 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/30 23:26:55 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		is_map_valid(char **map, int nb_lines, int nb_chars)
{
	if (check_line_len(map, nb_lines, nb_chars) == 0)
	{
		print_error();
		return (0);
	}
	if (check_lines_nb(map, nb_lines) == 0)
	{
		print_error();
		return (0);
	}
	if (check_valid_params(map) == 0)
	{
		print_error();
		return (0);
	}
	if (check_params_in_map(map) == 0)
	{
		print_error();
		return (0);
	}
	return (1);
}
