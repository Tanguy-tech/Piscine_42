/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 23:02:57 by lduplain          #+#    #+#             */
/*   Updated: 2020/09/27 23:34:41 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_hundred(char part[3], char str[3], char **dictionnary)
{
	if (part[0] != '0')
	{
		str[0] = part[0];
		str[1] = '\0';
		ft_putstr(get_value_by_key(dictionnary, str));
		ft_putstr(" ");
		ft_putstr(get_value_by_key(dictionnary, "100"));
	}
}

void	print_ten(char str[3], char part[3], char **dictionnary)
{
	str[0] = part[1];
	str[1] = part[2];
	str[2] = '\0';
	if (get_value_by_key(dictionnary, str) != 0)
	{
		if (part[0] != '0')
			ft_putstr(" ");
		ft_putstr(get_value_by_key(dictionnary, str));
		return ;
	}
	str[0] = part[1];
	str[1] = '0';
	str[2] = '\0';
	if (part[0] != '0')
		ft_putstr(" ");
	ft_putstr(get_value_by_key(dictionnary, str));
	if (part[2] != '0')
	{
		ft_putstr(" ");
		str[0] = part[2];
		str[1] = '\0';
		ft_putstr(get_value_by_key(dictionnary, str));
	}
}

void	print_part(char part[3], char **dictionnary)
{
	char	str[3];

	print_hundred(part, str, dictionnary);
	if (part[1] != '0')
		print_ten(str, part, dictionnary);
	else if (part[2] != '0')
	{
		str[0] = part[2];
		str[1] = '\0';
		if (part[0] != '0')
			ft_putstr(" ");
		ft_putstr(get_value_by_key(dictionnary, str));
	}
}

void	print_suffix(int index, char **dictionnary)
{
	int		i;
	char	*name;
	char	*to_search;

	to_search = malloc(3 * index + 2);
	to_search[0] = '1';
	i = 1;
	while (i < 3 * index + 1)
	{
		to_search[i] = '0';
		i++;
	}
	to_search[i] = '\0';
	name = get_value_by_key(dictionnary, to_search);
	ft_putstr(" ");
	ft_putstr(name);
	free(name);
	free(to_search);
}

void	print_number(char **parts, int part_count, char **dictionnary)
{
	int		i;

	i = part_count;
	while (--i)
	{
		if (!(parts[i][0] == '0' && parts[i][1] == '0' && parts[i][2] == '0'))
		{
			print_part(parts[i], dictionnary);
			print_suffix(i, dictionnary);
			if (i < part_count && !(parts[i - 1][0] == '0'
				&& parts[i - 1][1] == '0' && parts[i - 1][2] == '0'))
				ft_putstr(" ");
		}
	}
	print_part(parts[i], dictionnary);
	ft_putstr("\n");
}
