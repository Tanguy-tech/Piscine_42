/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 12:59:44 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/16 16:42:35 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int index)
{
	int i;

	i = 0;
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	if (index > 1)
		i = ft_fibonacci(index - 2) + ft_fibonacci(index - 1);
	return (i);
}
