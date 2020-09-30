/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:24:54 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/17 08:56:39 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		check_is_prime(int nb)
{
	int i;

	i = 3;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i = i + 2;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	if (nb <= 1)
		return (2);
	if (nb == 2 || nb == 2147483647)
		return (nb);
	if (nb % 2 == 0)
		nb++;
	while (check_is_prime(nb) == 0 && nb < 2147483647)
	{
		nb = nb + 2;
	}
	return (nb);
}
