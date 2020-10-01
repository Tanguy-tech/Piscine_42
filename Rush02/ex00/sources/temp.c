/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 14:11:30 by lduplain          #+#    #+#             */
/*   Updated: 2020/09/27 15:13:02 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	display(char **dictionnary)
{
	int i;

	i = 0;
	while (dictionnary[i] != 0)
	{
		printf("Line(%d): %s\n", i, dictionnary[i]);
		i++;
	}
}
