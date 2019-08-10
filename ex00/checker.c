/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:07:41 by lothieve          #+#    #+#             */
/*   Updated: 2019/08/10 22:17:12 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "check_struct.h"

int		check_view_col(int **grid, int range, int i, t_lr expected)
{
	int		x;
	t_lr	tmax;
	t_lr	views;

	tmax = (t_lr){ .l = 0, .r = 0 };
	views = (t_lr){ .l = 0, .r = 0 };
	range--;
	x = -1;
	while (++x <= range)
	{
		if (grid[x][i] > tmax.l)
		{
			tmax.l = grid[x][i];
			views.l++;
		}
		if (grid[range - x][i] > tmax.r)
		{
			tmax.r = grid[range - x][i];
			views.r++;
		}
	}
	if (views.r != expected.r || views.l != expected.l)
		return (0);
	return (1);
}

int		check_view_row(int *row, int range, t_lr expected)
{
	int		x;
	t_lr	tmax;
	t_lr	views;

	tmax = (t_lr){ .l = 0, .r = 0 };
	views = (t_lr){ .l = 0, .r = 0 };
	range--;
	x = -1;
	while (++x <= range)
	{
		if (row[x] > tmax.l)
		{
			tmax.l = row[x];
			views.l++;
		}
		if (row[range - x] > tmax.r)
		{
			tmax.r = row[range - x];
			views.r++;
		}
	}
	if (views.r != expected.r || views.l != expected.l)
		return (0);
	return (1);
}

int		check_row(int *row, int i, int range, int *input)
{
	int		x;
	int		y;
	t_lr	views;

	x = 0;
	while (x + 1 < range)
	{
		y = 0;
		while (y < range)
		{
			if (row[y] == 0)
				return (1);
			if (row[x] == row[y] && y != x)
				return (0);
			y++;
		}
		x++;
	}
	views = (t_lr){ .l = input[i + range * 2], .r = input[i + range * 3]};
	return (check_view_row(row, range, views));
}

int		check_col(int **grid, int i, int range, int *input)
{
	int		x;
	int		y;
	t_lr	views;

	x = 0;
	while (x + 1 < range)
	{
		y = 0;
		while (y < range)
		{
			if (grid[y][i] == 0)
				return (1);
			if (grid[x][i] == grid[y][i] && y != x)
				return (0);
			y++;
		}
		x++;
	}
	views = (t_lr){ .l = input[i], .r = input[i + range]};
	return (check_view_col(grid, range, i, views));
	return (1);
}

int		check(int **grid, int *input, int max, int range)
{
	int i;

	i = 0;
	while (i <= max)
	{
		if (!check_row(grid[i % range], i % range, range, input)
				|| !check_col(grid, i / range, range, input))
			return (0);
		i += range + 1;
	}
	return (1);
}
