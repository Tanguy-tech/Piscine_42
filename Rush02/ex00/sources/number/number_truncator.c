/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_truncator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 15:50:11 by lduplain          #+#    #+#             */
/*   Updated: 2020/09/27 23:36:07 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		g_i;
int		g_j;

void	a(int number_len, char *number, char **result)
{
	result[g_i] = malloc(3 * sizeof(char));
	g_j = -1;
	while (++g_j < 3 - number_len)
		result[g_i][g_j] = '0';
	while (g_j < 3)
	{
		result[g_i][g_j] = number[g_j + number_len - 3];
		g_j++;
	}
}

char	**truncate_number(char *number, int *table_size)
{
	char	*block;
	char	**result;
	int		number_len;

	number_len = ft_strlen(number);
	*table_size = (number_len / 3) + (number_len % 3 ? 1 : 0);
	result = malloc(*table_size * sizeof(char*));
	g_i = 0;
	while (number_len >= 3)
	{
		block = &number[number_len - 3];
		result[g_i] = malloc(3 * sizeof(char));
		g_j = -1;
		while (++g_j < 3)
			result[g_i][g_j] = block[g_j];
		number_len -= 3;
		g_i++;
	}
	if (number_len)
		a(number_len, number, result);
	return (result);
}
