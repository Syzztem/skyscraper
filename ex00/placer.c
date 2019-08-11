/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 08:53:42 by lothieve          #+#    #+#             */
/*   Updated: 2019/08/11 14:29:15 by lcalendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "placer.h"

void	free_grid(int **grid, int range)
{
	int i;

	i = -1;
	while (++i < range)
		free(grid[i]);
	free(grid);
}

int		pgrid(int **grid, int range)
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

int		fill_grid(int **grid, int *input, int range, int p)
{
	int i;
	int sq;

	sq = range * range;
	i = 0;
	while (i < range)
	{
		if (p < sq)
			grid[p / range][p % range] = ++i;
		if (check(grid, input, p, range))
		{
			if (p == sq)
				return (pgrid(grid, range));
			if (fill_grid(grid, input, range, p + 1) == 0)
				return (0);
		}
	}
	grid[p / range][p % range] = 0;
	return (-4);
}

int		place(int *input, int range)
{
	int **grid;
	int y;
	int i;

	if (!(grid = malloc(sizeof(int*) * range)))
		return (-1);
	y = 0;
	while (y < range)
	{
		if (!(grid[y] = malloc(sizeof(int) * range)))
			return (-1);
		y++;
	}
	i = 0;
	while (i < range * range)
	{
		grid[i / range][i % range] = 0;
		i++;
	}
	i = fill_grid(grid, input, range, 0);
	free_grid(grid, range);
	return (i);
}
