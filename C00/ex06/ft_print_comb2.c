/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 13:42:10 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/09 14:31:33 by tbillon          ###   ########lyon.fr   */
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

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_putnbr((a / 10));
			ft_putnbr((a % 10));
			ft_putchar(' ');
			ft_putnbr((b / 10));
			ft_putnbr((b % 10));
			if ((b != 99) || (a != 98))
			{
				write(1, ", ", 2);
			}
			b++;
		}
		a++;
	}
}
