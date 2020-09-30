/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:09:37 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/22 07:54:30 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_base(char *base);
int		size_num(int nb, char *base);

int		ft_lenght(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		neg_to_pos(int nb)
{
	if (nb < 0)
	{
		nb = nb * -1;
	}
	return (nb);
}

int		ft_check_num(int nb)
{
	if (nb < 0)
		return (1);
	return (0);
}

char	*if_null(char *final, char *base)
{
	final[0] = base[0];
	return (final);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	long int		i;
	unsigned int	nb;
	int				size_base;
	char			*final;

	if (!(final = malloc(sizeof(char) * (size_num(nbr, base) + 1))))
		return (NULL);
	final[size_num(nbr, base)] = '\0';
	size_base = ft_lenght(base);
	if (check_base(base) == 1)
	{
		nb = neg_to_pos(nbr);
		if (nb == 0)
			return (if_null(final, base));
		i = size_num(nbr, base) - 1;
		while (nb != 0)
		{
			final[i--] = base[nb % size_base];
			nb = nb / size_base;
		}
		if (ft_check_num(nbr) == 1)
			final[0] = '-';
		return (final);
	}
	return (0);
}
