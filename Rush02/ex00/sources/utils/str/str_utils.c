/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:45:44 by lduplain          #+#    #+#             */
/*   Updated: 2020/09/27 15:34:28 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**	Display a str
*/

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

/*
**	Copy n characters from src to dest
*/

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
**	Get the len of a str
*/

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
**	Compare to str
*/

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
**	Remove spaces from front ans back of a str
*/

char	*trim(char *str)
{
	int strlen;
	int	i;
	int	j;

	strlen = ft_strlen(str);
	i = 0;
	while (i < strlen && is_whitespace(str[i]))
		i++;
	j = strlen - 1;
	while (j > 0 && is_whitespace(str[j]))
		j--;
	str = ft_strncpy(str, &str[i], j - i + 1);
	return (str);
}
