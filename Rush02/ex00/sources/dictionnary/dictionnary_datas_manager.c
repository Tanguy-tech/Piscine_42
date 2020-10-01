/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionnary_datas_manager.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 13:47:35 by lduplain          #+#    #+#             */
/*   Updated: 2020/09/27 22:42:58 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**	Get the key of a dictionnary line
*/

char	*get_key(char *dictionnary_line)
{
	char	*result;
	int		i;

	i = 0;
	while (is_numeric(dictionnary_line[i]))
		i++;
	result = malloc(sizeof(char) * (i + 1));
	ft_strncpy(result, dictionnary_line, i);
	result[i] = 0;
	return (result);
}

/*
**	Get the value of a dictionnary line
*/

char	*get_value(char *dictionnary_line)
{
	char	*result;
	int		size;
	int		i;

	i = ft_strlen(dictionnary_line) - 1;
	while (is_printable(dictionnary_line[i], 0) && dictionnary_line[i] != ':')
		i--;
	size = ft_strlen(dictionnary_line) - i;
	result = malloc(sizeof(char) * (size + 1));
	ft_strncpy(result, &dictionnary_line[i + 1], size + 1);
	return (result);
}

/*
**	Get the key len of a dictionnary line
*/

int		get_key_len(char *dictionnary_line)
{
	int len;

	len = 0;
	while (is_numeric(dictionnary_line[len]))
		len++;
	return (len);
}

/*
**	Find or no the value associated to a key in the entire dictionnary
*/

char	*get_value_by_key(char **dictionnary, char *key)
{
	int i;

	i = 0;
	while (dictionnary[i] != 0)
	{
		if (ft_strcmp(get_key(dictionnary[i]), key) == 0)
			return (get_value(dictionnary[i]));
		i++;
	}
	return (0);
}
