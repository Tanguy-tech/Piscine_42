/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 10:02:29 by lduplain          #+#    #+#             */
/*   Updated: 2020/09/27 15:23:17 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort(int lines_counter, char **dictionnary)
{
	int		i;
	char	*temp;

	i = 0;
	while (i < lines_counter - 1)
	{
		if (get_key_len(dictionnary[i]) > get_key_len(dictionnary[i + 1]))
		{
			temp = dictionnary[i];
			dictionnary[i] = dictionnary[i + 1];
			dictionnary[i + 1] = temp;
			i = 0;
		}
		if (get_key_len(dictionnary[i]) == get_key_len(dictionnary[i + 1])
			&& ft_strcmp(dictionnary[i], dictionnary[i + 1]) > 0)
		{
			temp = dictionnary[i];
			dictionnary[i] = dictionnary[i + 1];
			dictionnary[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

char	**generate_table(char *dictionnary_path)
{
	char	**dictionnary;
	char	*dict_value;
	int		max_line_length;
	int		lines_counter;
	int		i;

	max_line_length = 0;
	lines_counter = count_lines(dictionnary_path, &max_line_length);
	if (lines_counter == -1)
		return (0);
	if (!(dictionnary = malloc(sizeof(char *) * (lines_counter + 1))))
		return (0);
	i = 0;
	while (i < lines_counter)
	{
		if (!(dict_value = malloc(sizeof(char) * (max_line_length + 1))))
			return (0);
		dictionnary[i] = dict_value;
		i++;
	}
	return (dictionnary);
}
