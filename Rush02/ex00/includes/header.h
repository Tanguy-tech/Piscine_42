/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:43:59 by lduplain          #+#    #+#             */
/*   Updated: 2020/09/27 18:48:06 by dburgun          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

/*
**	STR_UTILS
*/

void	ft_putstr(char *str);

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int		ft_strlen(char *str);

int		ft_strcmp(char *s1, char *s2);

char	*trim(char *str);

/*
**	CHAR_TYPE_CHECKER
*/

int		is_space(char c);

int		is_whitespace(char c);

int		is_numeric(char c);

int		is_printable(char c, int space_sensitive);

/*
**	ARGS_CHECKER
*/

int		check_dictionnary_path(char *dictionnary_path);

int		check_number(char *number);

int		valid_args(char *dictionnary_path, char *number);

/*
** ERROR
*/

int		print_error(int error_code);

/*
**	MALLOC_UTILS
*/

void	free_char_table(char **table, int length);

/*
**	READER
*/

int		open_file(char *dictionnary_path);

void	char_condition(
	int *char_counter, int *max_line_length, int *line_counter);

int		count_lines(char *dictionnary_path, int *max_line_length);

void	dictionnary_condition(
	int *char_counter, char **dictionnary, int *line_counter);

int		complete_dictionnary(char **dictionnary, char *dictionnary_path);

/*
**	TABLE_CREATOR
*/

char	**generate_table(char *dictionnary_path);

void	sort(int lines_counter, char **dictionnary);

/*
**	FORMAT
*/

char	*format(char *str);

void	format_dictionnary(char **dictionnary);

/*
**	DICTIONNARY_MANAGER
*/

char	*get_key(char *dictionnary_line);

char	*get_value(char *dictionnary_line);

char	*get_value_by_key(char **dictionnary, char *key);

int		get_key_len(char *dictionnary_line);

/*
**	NUMBER_TRUNCATOR
*/

char	**truncate_number(char *number, int *table_size);

/*
**	TEMP
*/

void	display(char **dictionnary);

/*
**	TEMP
*/
void	print_number(char **parts, int part_count, char **dictionnary);

#endif
