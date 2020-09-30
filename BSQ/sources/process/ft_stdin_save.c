/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:41:08 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/29 20:03:28 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_strcpy(char *a, char *b)
{
	int i;

	i = -1;
	while (a[++i])
		b[i] = a[i];
}

char	*ft_realloc(char *tab, int *len)
{
	char *new_tab;

	*len += 4000;
	if (!(new_tab = malloc(sizeof(char) * (*len + 1))))
		return (0);
	new_tab[*len] = '\0';
	ft_strcpy(tab, new_tab);
	free(tab);
	return (new_tab);
}

char	*ft_stdin_save(void)
{
	char		*map;
	int			i;
	char		c;
	int			len;

	i = 0;
	len = 4000;
	if ((map = malloc(sizeof(char) * len + 1)) == NULL)
		return (0);
	map[len] = '\0';
	while (read(0, &c, 1) > 0)
	{
		map[i++] = c;
		if (i == len)
			map = ft_realloc(map, &len);
	}
	map[i] = '\0';
	return (map);
}
