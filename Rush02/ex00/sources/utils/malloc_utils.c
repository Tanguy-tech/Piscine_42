/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:39:31 by lduplain          #+#    #+#             */
/*   Updated: 2020/09/27 15:23:20 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**	Free a double entry table of length lines
*/

void	free_char_table(char **table, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		free(table[i]);
		i++;
	}
	free(table);
}
