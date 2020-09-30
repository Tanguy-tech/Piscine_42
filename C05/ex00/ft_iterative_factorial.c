/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 13:00:50 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/16 18:15:20 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;
	int res;

	i = 1;
	res = nb;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (i < nb)
	{
		res = i * res;
		i++;
	}
	return (res);
}
