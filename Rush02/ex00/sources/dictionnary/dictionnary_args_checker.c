/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:04:44 by lduplain          #+#    #+#             */
/*   Updated: 2020/09/26 22:18:51 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_dictionnary_path(char *dictionnary_path)
{
	int fd;

	if ((fd = open(dictionnary_path, O_RDONLY)) == -1)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int		check_number(char *number)
{
	int i;

	i = 0;
	while (number[i])
	{
		if (!is_numeric(number[i]))
			return (0);
		i++;
	}
	return (1);
}

int		valid_args(char *dictionnary_path, char *number)
{
	if (!check_dictionnary_path(dictionnary_path))
		if (print_error(1))
			return (0);
	if (!check_number(number))
		if (print_error(0))
			return (0);
	return (1);
}
