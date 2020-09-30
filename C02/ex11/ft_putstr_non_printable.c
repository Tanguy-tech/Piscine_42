/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 10:55:55 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/12 18:57:38 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_if_printable(char *str)
{
	int check;
	int i;

	check = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] > 32 && str[i] < 127))
			check = 1;
		else
			i++;
	}
	return (check);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_check_if_printable(str) == 1)
		{
			while (str[i] > 31 && str[i] < 127)
			{
				i++;
			}
		}
	}
}
