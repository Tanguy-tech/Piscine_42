/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_type_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:54:56 by lduplain          #+#    #+#             */
/*   Updated: 2020/09/26 18:57:26 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		is_space(char c)
{
	return (c == ' ');
}

int		is_whitespace(char c)
{
	return ((c >= 9 && c <= 13) || is_space(c));
}

int		is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int		is_printable(char c, int space_sensitive)
{
	return (c >= (33 - space_sensitive) && c <= 126);
}
