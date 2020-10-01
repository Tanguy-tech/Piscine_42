/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:39:35 by lduplain          #+#    #+#             */
/*   Updated: 2020/09/27 23:31:35 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**init_dictionnary(char *dictionnary_path)
{
	char **dictionnary;

	dictionnary = generate_table(dictionnary_path);
	complete_dictionnary(dictionnary, dictionnary_path);
	format_dictionnary(dictionnary);
	return (dictionnary);
}

void	execute(char *number, int *part_count, char **dictionnary)
{
	char	**parts;

	parts = truncate_number(number, part_count);
	if (ft_strcmp(number, "0") == 0)
	{
		ft_putstr(get_value_by_key(dictionnary, "0"));
		ft_putstr("\n");
	}
	else
		print_number(parts, *part_count, dictionnary);
	free(parts);
}

int		main(int argc, char **argv)
{
	char	**dictionnary;
	char	*dictionnary_path;
	char	*number;
	int		part_count;

	if (argc == 1 || argc > 3)
		if (print_error(0))
			return (0);
	if (argc == 3)
	{
		dictionnary_path = argv[1];
		number = argv[2];
	}
	if (argc == 2)
	{
		dictionnary_path = "numbers.dict";
		number = argv[1];
	}
	if (!valid_args(dictionnary_path, number))
		return (0);
	dictionnary = init_dictionnary(dictionnary_path);
	execute(number, &part_count, dictionnary);
}
