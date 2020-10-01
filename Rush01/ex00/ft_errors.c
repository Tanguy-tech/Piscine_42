/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 10:38:08 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/20 14:52:46 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_new_str(char *str);
int		ft_strlen(char *str);

int		ft_errors(char *str)
{
	int		i;
	int		j;
	char	*newstr;

	if (!(newstr = ft_new_str(str)))
		return (0);
	i = ft_strlen(newstr);
	if ((i / 4) < 3 || (i / 4) > 9)
		return (0);
	j = 0;
	while (newstr[j] != '\0')
	{
		if (!((newstr[j] >= 49 && newstr[j] <= ((i / 4) + 48))))
			return (0);
		j++;
	}
	return (1);
}
