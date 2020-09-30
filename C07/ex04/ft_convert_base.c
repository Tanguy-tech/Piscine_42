/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:09:26 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/22 07:54:32 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_lenght(char *str);
char	*ft_putnbr_base(int nbr, char *base);

int		check_base(char *base)
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

int		size_num(int nb, char *base)
{
	int i;

	i = 0;
	if (nb < 0)
		i++;
	while (nb != 0)
	{
		nb = nb / ft_lenght(base);
		i++;
	}
	if (i == 0)
		return (1);
	return (i);
}

int		translate(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int calc;
	int len;
	int neg;

	i = 0;
	neg = 0;
	calc = 0;
	len = ft_lenght(base);
	if (check_base(base) == 1)
	{
		while (*str != '\0')
		{
			while ((str[i] == '-' || str[i] == '+') ||
					(str[i] >= 8 && str[i] <= 13) || (str[i] == 32))
				if (str[i++] == '-')
					neg++;
			while (translate(str[i], base) >= 0)
				calc = (calc * len + (translate(str[i++], base)));
			if (neg % 2 == 1)
				calc = calc * -1;
			return (calc);
		}
	}
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		newnb;
	char	*final;

	if ((check_base(base_from) == 0 || check_base(base_to) == 0))
		return (0);
	newnb = ft_atoi_base(nbr, base_from);
	final = ft_putnbr_base(newnb, base_to);
	return (final);
}
