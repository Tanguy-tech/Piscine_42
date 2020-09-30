/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 10:27:18 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/10 10:28:03 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int temp;

	i = -1;
	while (i < (size - 1))
	{
		if ((tab[i + 1]) < tab[i])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
		{
			i++;
		}
	}
}