/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 15:47:41 by lduplain          #+#    #+#             */
/*   Updated: 2020/09/27 15:47:45 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		print_error(int error_code)
{
	if (error_code == 0)
		ft_putstr("Error\n");
	if (error_code == 1)
		ft_putstr("Dict Error\n");
	return (1);
}
