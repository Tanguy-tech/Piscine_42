/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:59:38 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/16 13:59:29 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_display(char c)
{
	write(1, &c, 1);
}

int		check_base(char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int		check_if_valid(char *base)
{
	int i;
	int j;

	i = 0;
	j = 1;
	if (base[i + 1] == '\0' || base[i] == '\0')
		return (0);
	if (base[i] == '+' || base[i] == '-')
		return (0);
	while (base[i] != '\0')
	{
		while (base[j] != '\0')
		{
			if ((base[j] == '-' || base[j] == '+') ||
					(base[j] >= 9 && base[j] <= 13)
					|| (base[j] == 32) || base[i] == base[j])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int		ft_check_neg(int nb)
{
	if (nb < 0)
	{
		ft_display('-');
		nb = nb * -1;
	}
	return (nb);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	i;
	long		nb;
	int			size_base;
	char		final[500];

	nb = nbr;
	i = 0;
	size_base = check_base(base);
	if (check_if_valid(base) == 1)
	{
		nb = ft_check_neg(nb);
		if (nb == 0)
			ft_display(base[i]);
		while (nb != 0)
		{
			final[i] = base[nb % size_base];
			printf("=> %c\n", final[i]);
			nb = nb / size_base;
			i++;
		}
		while (i-- > 0)
		{
			ft_display(final[i]);
		}
	}
}
