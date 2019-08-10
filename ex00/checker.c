/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:07:41 by lothieve          #+#    #+#             */
/*   Updated: 2019/08/10 15:22:29 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int check_row(int *row, int range)
{
	int x;
	int y;

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
	return (1);
}

int check_col(int **grid, int i, int range)
{
	int x;
	int y;

	x = 0;
	while (x + 1 < range)
	{
		y = 0;
		while (y < range)
		{
			if (grid[x][i] == grid[y][i] && grid[x][i] != 0 && y != x)
				return (0);
			y++;
		}
		x++;
	}
	return(1);
}

int     check(int **grid, int *input, int max, int range)
{
	(void) input;
	int i;

	i = 0;
	while (i <= max)
	{
		if (!check_row(grid[i % range], range) || !check_col(grid, i / range, range))
			return (0);
		i += range + 1;
	}
	return (1);
}
