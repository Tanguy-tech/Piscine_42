/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 11:23:55 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/12 13:10:23 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_check(int x, int y)
{
	if (x > 0 && y > 0)
		return (1);
	else
		return (0);
}

void	ft_display(int i, int j, int x, int y)
{
	if (((i == 1) && j == 1) || (x == i && j == y && x > 1 && y > 1))
		ft_putchar('/');
	else if ((i == 1 && j > 1 && j < y)
			|| (i == x && j > 1 && j < y))
		ft_putchar('*');
	else if (((i > 1 && i < x) && (j != 1)) && (j < y))
		ft_putchar(' ');
	else if (((i < x) && (j <= y) && (i > 1))
			|| (i > 1 && i < x && x == y))
		ft_putchar('*');
	else if (j == y || i == x)
		ft_putchar(92);
}

void	rush(int x, int y)
{
	int i;
	int j;

	j = 0;
	if (ft_check(x, y) == 1)
	{
		while ((j++ <= y) && (j != y + 1))
		{
			i = 1;
			while (i <= x)
			{
				ft_display(i, j, x, y);
				i++;
			}
			ft_putchar('\n');
		}
	}
}
