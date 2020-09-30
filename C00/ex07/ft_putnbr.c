/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 09:58:18 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/09 13:23:38 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int i;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	i = nb;
	if (i > 9)
	{
		ft_putnbr(i / 10);
	}
	ft_putchar((i % 10) + 48);
}
