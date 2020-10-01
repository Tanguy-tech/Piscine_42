/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 09:57:18 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/27 15:37:38 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_format(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (is_numeric(str[i]))
			while (is_numeric(str[i]))
				i++;
		else
			return (0);
		while (is_space(str[i]))
			i++;
		if (str[i] == ':')
			i++;
		else
			return (0);
		while (is_space(str[i]))
			i++;
		if (is_printable(str[i], 0))
			while (is_printable(str[i], 0))
				i++;
		else
			return (0);
	}
	return (1);
}

void	format_dictionnary(char **dictionnary)
{
	int i;

	i = -1;
	while (dictionnary[++i] != 0)
		dictionnary[i] = trim(dictionnary[i]);
	sort(i, dictionnary);
}
