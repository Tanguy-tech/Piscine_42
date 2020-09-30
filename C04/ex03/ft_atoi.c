/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:23:18 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/15 14:55:54 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int i;
	int neg;
	int res;

	i = 0;
	neg = 0;
	res = 0;
	while (str[i] != '\0')
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		while (str[i] == '-' || str[i] == '+')
			if (str[i++] == '-')
				neg++;
		while (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + (str[i++] - 48);
		if (neg % 2 == 1)
			res = res * -1;
		return (res);
	}
	return (0);
}
