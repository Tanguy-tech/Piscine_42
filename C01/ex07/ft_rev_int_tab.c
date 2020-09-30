/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 18:25:58 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/10 14:31:25 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int newtab[size];
	int i;
	int j;

	j = size - 1;
	i = 0;
	while (i < size)
	{
		newtab[i] = tab[j];
		i++;
		j--;
	}
	i = 0;
	while (i < size)
	{
		tab[i] = newtab[i];
		i++;
	}
}
