/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 12:59:27 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/17 08:43:33 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb > (46340 * 46340))
		return (0);
	while ((i * i) < nb)
		i++;
	if ((i * i) == nb)
		return (i);
	else
		return (0);
}