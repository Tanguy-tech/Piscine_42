/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 19:08:21 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/12 21:08:06 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_up_to_low(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 64 && str[i] < 91)
			str[i] = str[i] + 32;
		i++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int check;

	i = 0;
	check = 1;
	ft_up_to_low(str);
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') ||
				(str[i] >= '0' && str[i] <= '9')))
			check = 1;
		else if ((str[i] >= 'a' && str[i] <= 'z') ||
					(str[i] >= '0' && str[i] <= '9'))
		{
			if (str[i] >= 'a' && str[i] <= 'z' && check == 1)
			{
				str[i] = str[i] - 32;
				check = 0;
			}
			else if (str[i] >= '0' && str[i] <= '9')
				check = 0;
		}
		i++;
	}
	return (str);
}
