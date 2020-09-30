/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 13:00:39 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/16 18:18:19 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int i;

	i = 0;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	if (nb > 0)
		i = nb * ft_recursive_factorial(nb - 1);
	return (i);
}
