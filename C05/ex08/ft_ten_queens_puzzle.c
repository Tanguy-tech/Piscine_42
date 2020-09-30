/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 11:05:46 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/17 16:48:43 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		abs_val(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

int		is_in_danger(int *positions, int hauteur, int test_col, int work_col)
{
	return (positions[test_col] == hauteur ||
	(work_col - test_col) == abs_val(hauteur - positions[test_col]));
}

void	display(int *solve, int n)
{
	int		i;
	char	a;

	i = 0;
	while (i < n)
	{
		a = solve[i] + '0';
		write(1, &a, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	solve(int *positions, int n, int c, int *solutions)
{
	int x;
	int y;

	if (c == n)
	{
		display(positions, n);
		*solutions += 1;
		return ;
	}
	y = 0;
	while (y < n)
	{
		x = 0;
		while ((x < c) && !(is_in_danger(positions, y, x, c)))
			x++;
		if (x < c)
		{
			y++;
			continue;
		}
		positions[c] = y;
		solve(positions, n, c + 1, solutions);
		y++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int positions[10];
	int solutions;

	solutions = 0;
	solve(positions, 10, 0, &solutions);
	return (solutions);
}
