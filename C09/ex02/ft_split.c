/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 09:24:22 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/25 09:24:24 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		isep(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		count_words(char *str, char *charset)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (*str)
	{
		if (isep(*str, charset) && i > 0)
		{
			count++;
			i = 0;
		}
		else if (!isep(*str, charset))
			i++;
		str++;
	}
	if (i > 0)
		count++;
	return (count);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

void	set_word(char **tab, int index, char *str, int size)
{
	tab[index] = malloc((size + 1) * sizeof(char));
	ft_strncpy(tab[index], str, size);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		nb_words;
	int		i1;
	int		j1;
	int		ccount;

	nb_words = count_words(str, charset);
	tab = malloc(sizeof(char*) * (nb_words + 1));
	i1 = 0;
	j1 = -1;
	ccount = 0;
	while (str[++j1] != '\0')
	{
		if (!isep(str[j1 - 1], charset) && isep(str[j1], charset) && ccount > 0)
		{
			set_word(tab, i1, &str[j1 - ccount], ccount);
			i1++;
			ccount = 0;
		}
		else if (!isep(str[j1], charset))
			ccount++;
	}
	set_word(tab, i1++, &str[j1 - ccount], ccount);
	tab[nb_words] = NULL;
	return (tab);
}
