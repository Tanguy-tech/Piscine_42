/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 16:56:54 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/20 17:54:49 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_lentot(char **strs, int size)
{
	int i;
	int lentot;

	i = 0;
	lentot = 0;
	while (i < size)
	{
		lentot = lentot + ft_len(strs[i]);
		i++;
	}
	return (lentot);
}

char	*ft_process(int size, char **strs, char *newstr, char *sep)
{
	int i;
	int j;
	int k;

	i = 0;
	j = -1;
	while (++j < size)
	{
		k = 0;
		while (strs[j][k] != '\0')
		{
			newstr[i] = strs[j][k];
			i++;
			k++;
		}
		k = 0;
		while (sep[k] != '\0' && j < size - 1)
		{
			newstr[i] = sep[k];
			i++;
			k++;
		}
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		lentot;
	char	*newstr;

	lentot = ft_lentot(strs, size) + (size * ft_len(sep));
	if (!(newstr = malloc(sizeof(char) * lentot + 1)))
		return (0);
	if (size == 0)
	{
		*newstr = '\0';
		return (newstr);
	}
	return (ft_process(size, strs, newstr, sep));
}
