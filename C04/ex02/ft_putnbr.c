/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 09:56:23 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/15 20:11:43 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_aff(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int i;

	i = nb;
	if (i < 0)
	{
		ft_aff('-');
		i = i * (-1);
	}
	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
		ft_aff(i + 48);
}
