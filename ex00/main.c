/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 11:05:43 by lothieve          #+#    #+#             */
/*   Updated: 2019/08/10 18:06:09 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdio.h>

int	error(void)
{
	write(1, "Error\n", 6);
	return (-1);
}

int	main(int ac, char **av)
{
	int i;

	if (ac == 2)
	{
		i = count_ints(av[1]);
		if (i % 4 != 0)
			return (error());
		i /= 4;
		place(str_sort(av[1]), i);
	}
	else
		return (error());
}
