/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 19:52:11 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/15 12:38:06 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int len1;
	unsigned int len2;

	len1 = ft_strlen(dest);
	len2 = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (len2);
	if (size <= len1)
		return (size + len2);
	while (dest[i] != '\0' && i < size - 1)
		i++;
	while (i < size - 1 && *src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (len1 + len2);
}
