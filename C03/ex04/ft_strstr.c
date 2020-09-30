/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 09:12:22 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/15 08:56:38 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		while (str[i + j] != '\0')
		{
			if (to_find[j] != str[i + j])
				break ;
			j++;
		}
		if (to_find[j] == '\0')
			return (str + i);
		j = 0;
		i++;
	}
	return (0);
}
