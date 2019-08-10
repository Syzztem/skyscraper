/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 08:53:42 by lothieve          #+#    #+#             */
/*   Updated: 2019/08/10 22:14:44 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "placer.h"

int	pgrid(int **grid, int range)
{
	int i;
	int j;

	i = 0;
	while (i < range)
	{
		j = 0;
		while (j < range)
		{
			ft_putnbr(grid[i][j]);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

int	fill_grid(int **grid, int *input, int range, int p)
{
	int i;

	i = 0;
	while (i < range)
	{
		if (p < range * range)
			grid[p / range][p % range] = ++i;
		if (check(grid, input, p, range))
		{
			if (p == range * range)
				return (pgrid(grid, range));
			if (fill_grid(grid, input, range, p + 1) == 0)
				return (0);
		}
	}
	grid[p / range][p % range] = 0;
	return (-1);
}

int	place(int *input, int range)
{
	int **grid;
	int y;
	int i;

	if (!(grid = malloc(sizeof(int*) * range)))
		return (0);
	y = 0;
	while (y < range)
	{
		if (!(grid[y] = malloc(sizeof(int) * range)))
			return (0);
		y++;
	}
	i = 0;
	while (i < range * range)
	{
		grid[i / range][i % range] = 0;
		i++;
	}
	return (fill_grid(grid, input, range, 0));
}
