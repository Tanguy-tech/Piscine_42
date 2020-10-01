/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:39:31 by lduplain          #+#    #+#             */
/*   Updated: 2020/09/27 12:15:07 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		open_file(char *dictionnary_path)
{
	int fd;

	if ((fd = open(dictionnary_path, O_RDONLY)) == -1)
		if (print_error(1))
			return (-1);
	return (fd);
}

void	char_condition(
	int *char_counter, int *max_line_length, int *line_counter)
{
	if (*char_counter > 0)
	{
		if (*char_counter > *max_line_length)
			*max_line_length = *char_counter;
		*char_counter = 0;
		*line_counter += 1;
	}
}

int		count_lines(char *dictionnary_path, int *max_line_length)
{
	char	buffer;
	int		line_counter;
	int		char_counter;
	int		fd;

	fd = open_file(dictionnary_path);
	line_counter = 0;
	char_counter = 0;
	while (read(fd, &buffer, 1))
	{
		if (buffer == '\n')
			char_condition(&char_counter, max_line_length, &line_counter);
		else
			char_counter++;
	}
	char_condition(&char_counter, max_line_length, &line_counter);
	close(fd);
	return (line_counter);
}

void	dictionnary_condition(
	int *char_counter, char **dictionnary, int *line_counter)
{
	if (*char_counter > 0)
	{
		dictionnary[*line_counter][*char_counter] = 0;
		*char_counter = 0;
		*line_counter += 1;
	}
}

int		complete_dictionnary(char **dictionnary, char *dictionnary_path)
{
	char	buffer;
	int		line_counter;
	int		char_counter;
	int		fd;

	fd = open_file(dictionnary_path);
	line_counter = 0;
	char_counter = 0;
	while (read(fd, &buffer, 1))
	{
		if (buffer == '\n')
			dictionnary_condition(&char_counter, dictionnary, &line_counter);
		else
		{
			dictionnary[line_counter][char_counter] = buffer;
			char_counter++;
		}
	}
	dictionnary[++line_counter] = 0;
	close(fd);
	return (1);
}
